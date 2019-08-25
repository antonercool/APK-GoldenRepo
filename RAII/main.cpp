#include <iostream>
#include <string>
#include "scopedRAII.hpp"
#include "genericRAII.hpp"

using namespace std;

int main()
{

    // Harded coded Int scoped ptr
    {
        ScopedRAII saveInt(new int(1));

        cout << "Print int : " << *saveInt << endl;

        (*saveInt) = 5;

        cout << "Print int : " << *saveInt << endl;
    }

    // Generic ScopedPtr work with anything
    {
        GenericRAII saveInt(new int(1));

        cout << "Print int : " << *saveInt << endl;

        (*saveInt) = 5;

        cout << "Print int : " << *saveInt << endl << endl;

        GenericRAII saveString(new string("HelloTHere"));

        cout << "save String : " << *saveString << endl;

        (*saveString) = "WhatIsUp";

        cout << "save String : " << *saveString << endl;

        saveString->append("123");

        cout << "Save string after use of operator -> append 123 : " << *saveString << endl;
        
    }

    return 0;
}