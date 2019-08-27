
template<class T>
class SmartPointer
{
private:
   T* _genericPtrHolder;
public:
    explicit SmartPointer(T* genRaiiPtr = 0){
        _genericPtrHolder = genRaiiPtr;
    }
    ~SmartPointer(){
          delete _genericPtrHolder;
    }

    T & operator*() const{
           return *_genericPtrHolder;
    } /* *raii retrieves data T& */
    
    T * operator->() const{
         return _genericPtrHolder;
    } /* raii> accesses data T* */

private:
    // Make these private so rule of 3 dont get fucked
    SmartPointer(const T &);
    SmartPointer &operator=(const T &);
};


//template class SmartPointer<int>;
