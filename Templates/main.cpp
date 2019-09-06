#include "myArray.hpp"
#include <string>

int main()
{

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

    for (int i : myTestArray)
    {
        cout << "Ranged based loop : i : " << i << endl;
    }

    cout << "Test size() --> " << myTestArray.size() << endl;

    std::cout << "Looking for '3'? " << (myFind(myTestArray.begin(), myTestArray.end(), 3) != myTestArray.end() ? "found" : "sry no") << std::endl;

    int const *  shouldNotFind = myFind(myTestArray.begin(), myTestArray.end(), 5);
    cout << "FindNumber : " << *shouldNotFind << endl;

    std::cout << "Looking for '3'? " << (myFind(myDoubleArray.begin(), myDoubleArray.end(), 3.0) != myDoubleArray.end() ? "found" : "sry no") << std::endl;

    {
        MyArray<string *, 3> myStringPtrs;

        string *myTestString1 = new string("String1");
        string *myTestString2 = new string("String2");
        string *myTestString3 = new string("String3");

        myStringPtrs.fill(myTestString1);
        myStringPtrs.fill(myTestString2);
        myStringPtrs.fill(myTestString3);

        for (string *s : myStringPtrs)
        {
            cout << "Sting s : " << *s << endl;
        }

        string *testThatString1 = myStringPtrs[0];

        cout << "Should be String1  --> was : " << *testThatString1 << endl;

        myStringPtrs[1] = new string("NewString");

        cout << "Should be NewString  --> was : " << *myStringPtrs[1] << endl;

        cout << (myfind(myStringPtrs.begin(), myStringPtrs.end(), string("Hello")) == myStringPtrs.end() ? "Hello Found" : " Hello notFound") << endl;
    }

    auto myAccumulationIntResult = myAccumalation(myTestArray);
    auto myAccumulationDoubleResult = myAccumalation(myDoubleArray);
    

    cout << "Acummulated Int result " << myAccumulationIntResult << endl;
    cout << "Acummulated Double result " << myAccumulationDoubleResult << endl;


    return 0;
}