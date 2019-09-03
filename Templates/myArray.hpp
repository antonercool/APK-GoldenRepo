#pragma once
#include <iostream>

using namespace std;

template<typename T, size_t size>
class MyArray
{
private:
    T _array[size];
    T* _currentIndexPtr;
public:
    MyArray(){
        // Initialize currentIndexPtr to the first element
        _currentIndexPtr = &_array;
    }
    ~MyArray();

    void fill(const T& itemToFill){

        bool canInsert = ((size-1)>=_currentIndex ) ? false : true;

        if (canInsert)
        {
            _currentIndexPtr++;
            *_currentIndexPtr = itemToFill;
        }
        else
        {
            cout << "Instance of my Array is full" << endl;   
        }
    }

    T* begin(){
        return &_array;
    }

    T* end(){
        return (&_array) + size;
    }

    T& operator [] (int index){
        return *((&_array) + index);
    }

    size_t size(){
        return size;
    }

};

