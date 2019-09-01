#include <iostream>
#include <string>
#include "scopedRAII.hpp"
#include "genericRAII.hpp"
#include "sharedPointer.hpp"

using namespace std;

int main()
{

    // Harded coded Int scoped ptr
    {
        ScopedRAII saveInt(new int(1));

        cout << "Print int : " << *saveInt << endl;

        (*saveInt) = 5;

        cout << "Print  saveInt : " << *saveInt << endl;
    }

    // Generic ScopedPtr work with anything
    {
        SmartPointer saveInt(new int(1));

        cout << "Print int : " << *saveInt << endl;

        (*saveInt) = 5;

        cout << "Print int : " << *saveInt << endl << endl;

        SmartPointer saveString(new string("HelloTHere"));

        cout << "save String : " << *saveString << endl;

        (*saveString) = "WhatIsUp";

        cout << "save String : " << *saveString << endl;

        saveString->append("123");

        cout << "Save string after use of operator -> append 123 : " << *saveString << endl;
        
    }

    // Test of copy constructor 
    {
        // Normal constructor
        SharedPointer<int> intShared(new int(1));

        // copy constructor
        SharedPointer<int> intShared2 = intShared;

        // copy constructor
        SharedPointer<int> intShared3(intShared);

    }

    // Test of assignment
    {
          // Normal constructor
        SharedPointer<int> intShared(new int(1));

        // Normal constructor    
        SharedPointer<int> intShared2(new int(123));

        // Normal constructor
        SharedPointer<int> intShared3(new int(1));

        // assignment
        intShared = intShared2;
 
        // assignment
        intShared3 = intShared2;


    }

    // Bool operatoer // How to use it ? 
    {   
        // When can this happend?? No one has acces to the private pointer
        int* intPtr = new int(1);
        SharedPointer<int> intShared(intPtr);

        // Whoops we cannot do this becuase constructor takes a copy of a pointer
        // we delete heap resource, but we cannot avoid the dangling pointer inside intShared
        delete intPtr;
        intPtr = nullptr;


        if(intShared){
            cout << "The sharedPointerValid"  << endl;
        }
        else
        {
            cout << "The sharedPointerIsNotValid"  << endl;
        }
        
    }

    // == operator
    {
        SharedPointer<int> intShared(new int(1));

        // Normal constructor    
        SharedPointer<int> intShared2(new int(123));

     
        // assignment
        intShared = intShared2;
 
       
       if(intShared2 == intShared){
           cout << "yes intShared2 == intShared" << endl;
       }


    }



    return 0;
}