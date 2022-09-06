/*
 *  main.cpp
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



#include "main.h"


int main(int argc, const char * argv[])
{
    try
    {
        cout << "testing default constructor..." << endl;

        RD_Array<char> RD1;

        cout << "RD_Array RD1 - size: " << RD1.size() << " capacity " << RD1.capacity() << endl;
        cout << "array contents:" << endl;
        
        for ( unsigned long i = 0; i < RD1.size(); i++ )
        {
            cout << RD1.at(i) << " ";
        }

        cout << endl << endl;

        cout << "testing constructor with parameters..." << endl;

        RD_Array<char> RD2( 8, 'a' );

        cout << "RD_Array RD2 - size: " << RD2.size() << " capacity " << RD2.capacity() << endl;
        cout << "array contents:" << endl;
        
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2.at(i) << " ";
        }

        cout << endl << endl;

        cout << "testing copy constructor..." << endl;
        cout << "RD_Array RD2 - size: " << RD2.size() << " capacity " << RD2.capacity() << endl;

        RD_Array<char> RD3(RD2);
        cout << "RD_Array RD3 - size: " << RD3.size() << " capacity " << RD3.capacity() << endl;
        cout << endl;

        cout << "array contents of the original:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2.at(i) << " ";
        }
        cout << endl << endl;

        cout << "array contents of the copy:" << endl;
        for ( unsigned long i = 0; i < RD3.size(); i++ )
        {
            cout << RD3.at(i) << " ";
        }
        cout << endl << endl;

        cout << "prove deep copy by clearing the original array contents..." << endl << endl;
        RD2.clear();
        
        cout << "array contents of the original after call to clear:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2.at(i) << " ";
        }
        cout << endl;
        
        cout << "array contents of the copy:" << endl;
        for ( unsigned long i = 0; i < RD3.size(); i++ )
        {
            cout << RD3.at(i) << " ";
        }
        cout << endl << endl;

        cout << "testing operator=..." << endl;

        cout << "RD_Array RD3 - size: " << RD3.size() << " capacity " << RD3.capacity() << endl;

        RD2 = RD3;
        cout << "RD_Array RD2 - size: " << RD2.size() << " capacity " << RD2.capacity() << endl;
        cout << endl;

        cout << "array contents of the original:" << endl;
        for ( unsigned long i = 0; i < RD3.size(); i++ )
        {
            cout << RD3.at(i) << " ";
        }
        cout << endl << endl;

        cout << "array contents of the copy:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2.at(i) << " ";
        }
        cout << endl << endl;

        cout << "prove deep copy by clearing the original array contents..." << endl << endl;
        RD3.clear();
        
        cout << "array contents of the original after call to clear:" << endl;
        for ( unsigned long i = 0; i < RD3.size(); i++ )
        {
            cout << RD3.at(i) << " ";
        }
        cout << endl;
        
        cout << "array contents of the copy:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2.at(i) << " ";
        }
        cout << endl << endl;

        cout << "testing at method..." << endl;

        cout << "displaying array contents using the at method:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2.at(i) << " ";
        }
        cout << endl << endl;

        cout << "testing operator[]..." << endl;
 
        cout << "displaying array contents using the [] method:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "testing size and capacity methods..." << endl;

        cout << "displaying array contents:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "array has size " << RD2.size() << " and capacity " << RD2.capacity();
        cout << endl << endl;

        cout << "testing insert method..." << endl;

        cout << "array contents of the original:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "inserting character 'w' at the front of the array" << endl << endl;
        RD2.insert( 0, 'w' );

        cout << "array contents after the insert:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "testing push_back method..." << endl;

        cout << "array contents of the original:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "pushing character 'w' at the back of the array" << endl << endl;
        RD2.push_back( 'w' );

        cout << "array contents after the push_back:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "testing pop_back method..." << endl;

        cout << "array contents of the original:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "popping character 'w' at the back of the array" << endl << endl;
        RD2.pop_back();

        cout << "array contents after the pop_back:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;
    
        cout << "testing resize method..." << endl;

        cout << "array contents of the original:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "resizing array to size 4" << endl << endl;
        RD2.resize( 4 );
 
        cout << "array contents after the resize:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "resizing array to size 6" << endl << endl;
        RD2.resize( 6, 'c' );
 
        cout << "array contents after the second resize:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "resizing array to size 12" << endl << endl;
        RD2.resize( 12, 'y' );

        cout << "array contents after the second resize:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "testing clear and empty method" << endl << endl;

        cout << "array contents of the original:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "clearing the array" << endl << endl;
        RD2.clear();

        cout << "array contents after the clear:" << endl;
        for ( unsigned long i = 0; i < RD2.size(); i++ )
        {
            cout << RD2[i] << " ";
        }
        cout << endl << endl;

        cout << "if it is empty, output \"It is empty!\"" << endl << endl;
        if ( RD2.empty() )
           cout << "It is empty!";
        else
           cout << "It is not empty!";

        cout << endl << endl;

        cout << "finally demonstarting destructor..." << endl << endl;
	  
    }
    catch( bad_vehicle_code &bvc )
    {
        cout << "ERROR: caught bad_vehicle_code exception in function main\n";
        cout << bvc.what() << endl;
    }
    catch( invalid_argument &ia )
    {
        cout << "ERROR: caught invalid_argument exception in function main\n";
        cout << ia.what() << endl;
    }
    catch ( std::out_of_range &oor )
    {
        cout << "ERROR: caught out_of_range exception in function main\n";
        cout << oor.what() << endl;
    }
    catch( no_such_object &nso )
    {
        cout << "ERROR: caught no_such_object exception in function main\n";
        cout << nso.what() << endl;
    }
    catch( std::logic_error &le )
    {
        cout << "ERROR: caught logic_error exception in function main\n";
        cout << le.what() << endl;
    }
    catch( std::bad_alloc &ba )
    {
        cout << "ERROR: caught bad_alloc exception in function main\n";
        cout << ba.what() << endl;
    }
    catch( std::exception &e )
    {
        cout << "ERROR: caught exception exception in function main\n";
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "ERROR: unknown exception caught in function main\n";
    }

    return 0;  


} // END function main	