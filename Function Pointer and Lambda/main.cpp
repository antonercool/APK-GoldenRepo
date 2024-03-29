#include <iostream>
#include "myFunctor.hpp"

using namespace std;

void helloWorld(int number){
    cout << "helloWorld number : " << number << endl;
}



int main(){

    // THE SAME thing // without & address operator, the compiler implicit takes the address
    auto aHelloWorldFunction1 = helloWorld;
    auto aHelloWorldFunction2 = &helloWorld;

    // what type is auto ? 
    void(*aHelloWorldFunction3)(int) = helloWorld;

    // that is ugly // we can typedef it
    typedef void(*HelloWorlFunction)(int);
    HelloWorlFunction aHelloWorldFunction4 = helloWorld;  // &helloWorld;

    // call them 
    aHelloWorldFunction1(1);
    aHelloWorldFunction2(2);
    aHelloWorldFunction3(3);
    aHelloWorldFunction4(4);

    // with lambda
    HelloWorlFunction aHelloWorldLamdaFucntion = [](int number){cout << "helloWorld number : " << number << endl;};
    aHelloWorldLamdaFucntion(5);


    MyFunctor myFunctor;
    // with functor
    myFunctor(4);
 



    return 0;
}