#include <iostream>
#pragma once

using namespace std;

class MyFunctor
{
private:
    /* data */
public:
    void operator()(int number){
        std::cout << "HelloWorld MyFunctor, number : " << number << endl;     
    }    
    
};


