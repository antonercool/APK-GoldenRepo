
template<class T>
class GenericRAII
{
private:
   T* _genericPtrHolder;
public:
    explicit GenericRAII(T* genRaiiPtr = 0){
        _genericPtrHolder = genRaiiPtr;
    }
    ~GenericRAII(){
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
    GenericRAII(const T &);
    GenericRAII &operator=(const T &);
};


//template class GenericRAII<int>;
