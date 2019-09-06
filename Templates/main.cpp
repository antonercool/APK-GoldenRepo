#include "myArray.hpp"


int main (){

    MyArray<int, 5> myTestArray;
    MyArray<double, 6> myDoubleArray;

    myDoubleArray.fill(0.23);
    myDoubleArray.fill(234.23);
    myDoubleArray.fill(34.34);
    myDoubleArray.fill(456.432);
    myDoubleArray.fill(0.453);


    myTestArray.fill(0);  
    myTestArray.fill(1);
    myTestArray.fill(2);
    myTestArray.fill(3);  
    myTestArray.fill(4);

    for (size_t i = 0; i < myTestArray.size(); i++)
    {
        cout << myTestArray[i] << endl;
    }


    for(int i : myTestArray){
        cout << "Ranged based loop : i : "  <<  i << endl;
    }

    cout << "Test size() --> " << myTestArray.size() << endl;
    
    std::cout << "Looking for '3'? " << (myFind(myTestArray.begin (), myTestArray.end(), 3) !=myTestArray.end()? "found" : "sry no") << std::endl;

    int* shouldNotFind = myFind(myTestArray.begin(), myTestArray.end(), 5);
    cout << "FindNumber : " << *shouldNotFind << endl;

    std::cout << "Looking for '3'? " << (myFind(myDoubleArray.begin (), myDoubleArray.end(), 3.0) !=myDoubleArray.end()? "found" : "sry no") << std::endl;


    return 0;
}