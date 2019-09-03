#include "myArray.hpp"


int main (){

    MyArray<int, 5> myTestArray;


    myTestArray.fill(0);  
    myTestArray.fill(1);
    myTestArray.fill(2);
    myTestArray.fill(3);  
    myTestArray.fill(4);

    for (size_t i = 0; i < myTestArray.size; i++)
    {
        cout << myTestArray[i] << endl;
    }
    
    




    return 0;
}