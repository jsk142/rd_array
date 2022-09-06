/*
 *  rd_array.h
 *
 *  COSC 052 Fall 2019
 *  Project #5
 *
 *  Due on: DEC 5, 2019
 *  Author: jsk142
 *
 *
 *  In accordance with the class policies and Georgetown's
 *  Honor Code, I certify that, with the exception of the
 *  class resources and those items noted below, I have neither
 *  given nor received any assistance on this project.
 *
 *  References not otherwise commented within the program source code.
 *  Note that you should not mention any help from the TAs, the professor,
 *  or any code taken from the class textbooks.
 */


#ifndef _COSC052_FALL2019_P5_RD_ARRAY_H_
#define _COSC052_FALL2019_P5_RD_ARRAY_H_


using std::bad_alloc;
using std::out_of_range;
using std::exception;
using std::vector;
using std::cout;
using std::endl;


template <typename T>
class RD_Array {
    
public:
    RD_Array();
    RD_Array( const unsigned long, const T& = T() );
    RD_Array( const RD_Array<T> & );
    ~RD_Array();
    
    const RD_Array<T> &operator=( const RD_Array<T>& );
    
    T& at( const unsigned long ) const;
    T& operator[]( const unsigned long ) const;
    
    unsigned long size() const { return currentSize; }
    unsigned long capacity() const { return currentCapacity; }
    
    void insert( const unsigned long, const T& );
    void push_back( const T& );
    void pop_back();
    
    void resize( const unsigned long, const T& = T() );
    void clear();
    bool empty() const;

    
private:
    T* contents;
    unsigned long currentSize;
    unsigned long currentCapacity;
    
    void increaseCapacity();
    
}; // END RD_Array<T> class declaration






/****************************************************************************
 ****************************************************************************
 **                                                                        **
 **                    class RD_Array implementation                       **
 **                                                                        **
 ****************************************************************************
 ****************************************************************************/



/****************************************************************************
 **                                                                        **
 **                            private methods                             **
 **                                                                        **
 ****************************************************************************/

/****************************************************************************
 *                           increaseCapacity                               *
 ****************************************************************************/


template <typename T>
void RD_Array<T>::increaseCapacity()
{
    unsigned long newCapacity;
    unsigned long oldSize;

    if ( currentCapacity == 0 )
    {
        this->resize( 1 );
        currentSize = 0;
    }    
    else
    {
        oldSize = currentSize;
        newCapacity = 2 * currentCapacity;

        this->resize( newCapacity );
        currentSize = oldSize;
    }   
    
} // END increaseCapacity method of RD_Array class



/****************************************************************************
 **                                                                        **
 **                            public methods                              **
 **                                                                        **
 ****************************************************************************/

/****************************************************************************
 *                         default constructor                              *
 ****************************************************************************/

template <typename T>
RD_Array<T>::RD_Array()
{
    currentSize = 0;
    currentCapacity = 0;
    
    contents = NULL;
    
} // END default constructor RD_Array class



/****************************************************************************
 *                      constructor with parameters                         *
 ****************************************************************************/

template <typename T>
RD_Array<T>::RD_Array( const unsigned long size, const T& obj )
{
    currentSize = size;
    currentCapacity = size;

    contents = new T[currentCapacity];

    for ( unsigned long i = 0; i < currentSize; i++ )
    {
        contents[i] = obj;
    }	
    
} // END constructor with int, T parameters RD_Array class



/****************************************************************************
 *                           copy constructor                               *
 ****************************************************************************/

template <typename T>
RD_Array<T>::RD_Array( const RD_Array<T> & otherArray )
{
    this->currentSize = otherArray.currentSize;
    this->currentCapacity = otherArray.currentCapacity;

    contents = new T[currentCapacity];

    for ( unsigned long i = 0; i < currentSize; i++ )
    {
        this->contents[i] = otherArray.contents[i];
    }
    
} // END copy constructor for class RD_Array



/****************************************************************************
 *                                destructor                                *
 ****************************************************************************/

template <typename T>
RD_Array<T>::~RD_Array()
{
    cout << "entering destructor..." << endl;

    delete [] contents;

    cout << "exiting destructor..." << endl;
    
} // END destructor for RD_Array class



/****************************************************************************
 *                  overloaded assignment operator                          *
 ****************************************************************************/

template <typename T>
const RD_Array<T> &RD_Array<T>::operator=( const RD_Array<T> &otherArray )
{
    if ( this != &otherArray )
    {
        delete [] contents;

        this->currentSize = otherArray.currentSize;
        this->currentCapacity = otherArray.currentCapacity;

        contents = new T[currentCapacity];

        for ( unsigned long i = 0; i < currentSize; i++ )
        {
            this->contents[i] = otherArray.contents[i];
        }
    }
    
    return *this;
    
} // END overloaded assignment operator class RD_Array



/****************************************************************************
 *                              at method                                   *
 ****************************************************************************/

template <typename T>
T& RD_Array<T>::at( const unsigned long ndx ) const
{
    // Throw out_of_range exception if the parameter is within range
    if ( ndx < 0 || ndx >= currentSize )
    {
        throw std::out_of_range("ERROR: in RD_Array<T>:at() index passed not valid!\n");
    }
    
    return contents[ndx];
    
} // END at method class RD_Array



/****************************************************************************
 *                    overloaded subscript operator                         *
 ****************************************************************************/

template <typename T>
T& RD_Array<T>::operator[]( const unsigned long ndx ) const
{
    return this->at(ndx);
    
} // END overloaded subscript operator class RD_Array



/****************************************************************************
 *                             insert method                                *
 ****************************************************************************/

template <typename T>
void RD_Array<T>::insert( const unsigned long ndx, const T& value )
{
    if ( ndx < 0 || ndx > currentSize )
    {
        throw std::out_of_range("ERROR: in RD_Array<T>:at() index passed not valid!\n");
    }

    if ( currentSize == currentCapacity )
    {
        increaseCapacity();
    }

    if ( currentSize != 0 )
    {
        for ( unsigned long i = currentSize; i >= ndx + 1; i-- )
        {
            contents[ i ] = contents[ i - 1];
        }  
    }

    contents[ndx] = value;

    currentSize++;
        
} // END insert method class RD_Array



/****************************************************************************
 *                           push_back method                               *
 ****************************************************************************/

template <typename T>
void RD_Array<T>::push_back( const T& value)
{
    insert( currentSize, value );
    
} // END push_back method class RD_Array



/****************************************************************************
 *                            pop_back method                               *
 ****************************************************************************/

template <typename T>
void RD_Array<T>::pop_back()
{
    if ( this->empty() )
    {
        throw no_such_object("ERROR: The array is empty!\n");
    }

    currentSize--;
    
} // END pop_back method class RD_Array



/****************************************************************************
 *                             resize method                                *
 ****************************************************************************/

template <typename T>
void RD_Array<T>::resize( const unsigned long newSize, const T& value )
{
    unsigned long oldSize;

    if ( newSize < currentSize)
    {
        currentSize = newSize;
    }
    else if ( newSize <= currentCapacity )
    {
        oldSize = currentSize;
        currentSize = newSize;

        for ( unsigned long i = oldSize; i < currentSize; i++ )
        {
            contents[i] = value;
        }
    }
    else 
    {
        oldSize = currentSize;
        currentSize = newSize;
        currentCapacity = newSize;

        T *temp = new T[currentCapacity];

        for ( unsigned long i = 0; i < oldSize; i++ )
        {
            temp[i] = contents[i];
        }

        for ( unsigned long i = oldSize; i < currentSize; i++ )
        {
            temp[i] = value;
        }

        delete [] contents;
        contents = temp;
    }

    
} // END resize method class RD_Array



/****************************************************************************
 *                             empty method                                *
 ****************************************************************************/

template <typename T>
bool RD_Array<T>::empty() const
{
    return currentSize == 0;   
    
} // END empty method class RD_Array



/****************************************************************************
 *                             clear method                                 *
 ****************************************************************************/

template <typename T>
void RD_Array<T>::clear()
{
    currentSize = 0;
    
} // END clear method class RD_Array

















#endif /* _COSC052_FALL2019_P5_RD_ARRAY_H_ */