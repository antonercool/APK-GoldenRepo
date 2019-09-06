#pragma once
#include <iostream>

using namespace std;

template <typename T, size_t _size>
class MyArray
{
private:
    T _array[_size];
    size_t _currentIndex = 0;

public:

    typedef T value_type; 
    MyArray() {}
    ~MyArray() {}

    void fill(const T &itemToFill)
    {

        if (_size == 0)
        {
            return;
        }

        bool canInsert = _size == _currentIndex ? false : true;

        if (canInsert == true)
        {
            _array[_currentIndex] = itemToFill;
            _currentIndex = _currentIndex + 1;
        }
        else
        {
            cout << "Instance of my Array is full" << endl;
        }
    }

    const T* begin() const
    {
        // returns first address // same as _array
        return &_array[0];
    }

    const T* end() const
    {
        // return address of end + 1 (Size of T in addresses)
        return (&_array[_size - 1]) + 1;
    }

    T& operator[](int index)
    {
        return _array[index];
    }

    size_t size()
    {
        return _size;
    }
};

// _size cannot have default values
template <typename T, size_t _size>
class MyArray<T *, _size>
{

private:
    T *_array[_size];
    size_t _currentIndex = 0;

public:
    MyArray() {}

    ~MyArray()
    {
        cout << "Deleting all allocated mem for each pointer in array.. " << endl;
        for (int i = 0; i < _size; i++)
        {
            delete _array[i];
            _array[i] = nullptr;
        }
    }

    void fill(T *&itemToFill)
    {
        if (_size == 0)
        {
            return;
        }

        bool canInsert = _size == _currentIndex ? false : true;

        if (canInsert == true)
        {
            _array[_currentIndex] = itemToFill;
            _currentIndex = _currentIndex + 1;
        }
        else
        {
            cout << "Instance of my Array is full" << endl;
        }
    }

    int t = 5;
    int *ptr = &t;

    T **begin()
    {
        // returns first address // same as _array
        return &_array[0];
    }

    T **end()
    {
        // return address of end + 1 (Size of T in addresses)
        return (&_array[_size - 1]) + 1;
    }

    T *&operator[](int index)
    {
        return _array[index];
    }

    size_t size()
    {
        return _size;
    }
};

template <typename T>
T *myFind(T *first, T *last, const T &v)
{
    for (T *it = first; it != last; it++)
    {
        if (v == *it)
        {
            return it;
        }
    }

    return last;
}

template <typename T, typename V>
T *myFind(T *first, T *last, const V &v)
{
    for (T *it = first; it != last; it++)
    {
        if (v == *it)
        {
            return it;
        }
    }
    return last;
}

template <typename T, typename V>
T **myfind(T **first, T **last, const V &v)
{
    for (T **it = first; it != last; it++)
    {
        if (**it == v)
        {
            return it;
        }
    }
    return last;
}

template <typename U>
typename U::value_type myAccumalation(const U& u)
{
    typename U::value_type m = typename U::value_type();

    for(auto first : u)
    {
        m += first;
    }

    return m;
}