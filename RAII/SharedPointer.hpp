
template <typename T>
class SharedPointer
{
private:
    T* _genericSharedPtr;
    size_t* _count;
public:
    // First time a client gives heap allocated resource
    // SharedPointer allocated a count object on the heap and initializes it to 1 (One client atm)
    SharedPointer(T* genericSharedPtr){
        _genericSharedPtr = genericSharedPtr;
        _count = new size_t(1);
    }
    
    // Up hold rule of 3
    ~SharedPointer();
    SharedPointer& operator=(const SharedPointer &);
    SharedPointer(const SharedPointer &);

    // Overload dereference operator -- so client can acces its data this way
    T& operator*() const
    {
        return *_genericPtrHolder;
    } /* *raii retrieves data T& */

    // overloads -> acces operator -- so client can acces its data this way
    T *operator->() const
    {
        return _genericPtrHolder;
    } /* raii> accesses data T* */

    size_t count();
};
