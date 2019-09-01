#include <iostream>

using namespace std;

#pragma once

template <typename T>
class SharedPointer
{
private:
    T *_genericSharedPtr;
    size_t *_count;

public:
    // First time a client gives heap allocated resource
    // SharedPointer allocated a count object on the heap and initializes it to 1 (One client atm)
    explicit SharedPointer(T *genericSharedPtr)
    {
        _genericSharedPtr = genericSharedPtr;
        _count = new size_t(1);
    }

    // Up hold rule of 3
    ~SharedPointer()
    {
        // NOTE! *testPtr--
        // THIS is wrong! checkout --> adressBefore : 0xee6e58   adressAfter : 0xee6e54 --> because
        // C++ predecence https://en.cppreference.com/w/cpp/language/operator_precedence
        // postfix "--"" has higher priority than  "*" direfernce operator !
        
        cout << "Desctructor called count before decrement : " << *_count;
        --(*_count);
        // if count i == 0 we need to release our resources
        if (*_count == 0)
        {
           cout << ", count after : " << *_count << ", deleting count and data" << endl;
            delete _count;
            delete _genericSharedPtr;

            // Avoid dangling pointers
            _count = nullptr;
            _genericSharedPtr = nullptr;
        }
        else
        {
            cout << ", count after : " << *_count << endl;
        }
               
    }

    // & is const by default // const & is a ref which cannot change to object (ReadOnly)
    SharedPointer &operator=(const SharedPointer & objectToAssignFrom)
    {
        // Dont assign to it self // check whether this happends
        if(this == &objectToAssignFrom){
            return *this;
        }

        cout << "Start -- Assigment operator called, myCounter = " << *_count << " , objectToAssignFrom's count : " << *objectToAssignFrom._count << endl;

        // Decrement before we leave
        --(*_count); 

        // if we are last we clean
        if (*_count == 0)
        {
           cout << ", count after : " << *_count << ", deleting count and data" << endl;
            delete _count;
            delete _genericSharedPtr;

            // Avoid dangling pointers
            _count = nullptr;
            _genericSharedPtr = nullptr;
        }
        
        //then just switch over
        _count = objectToAssignFrom._count;
        ++(*_count); 

        _genericSharedPtr = objectToAssignFrom._genericSharedPtr;

        // return dereference of thisPtr
        cout << "END -- Assigment operator called, myCounter = " << *_count << " , objectToAssignFrom's count : " << *objectToAssignFrom._count << endl;
        
        return *this;
       
    }

    explicit SharedPointer(const SharedPointer &objectToCopyFrom)
    {

        cout << "Start -- CopyConstructor called, " << "objectTCopyFrom's count : " << *objectToCopyFrom._count << endl;
        // Point to the counter object // increment another client which has acces
        _count = objectToCopyFrom._count;
        ++(*_count);

        // point the the shared data
        _genericSharedPtr = objectToCopyFrom._genericSharedPtr;

        cout << "END -- CopyConstructor operator called, myCounter = " << *_count << " , objectToCopyFrom's count : " << *objectToCopyFrom._count << endl;
    }

    // Overload dereference operator -- so client can acces its data this way
    T& operator*() const
    {
        return *_genericSharedPtr;
    } /* *raii retrieves data T& */

    // overloads -> acces operator -- so client can acces its data this way
    T* operator->() const
    {
        return _genericSharedPtr;
    } /* raii> accesses data T* */

    size_t count(){
        return *_count;
    }
};
