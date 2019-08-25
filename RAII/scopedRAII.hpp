class ScopedRAII
{
private:
    int *_intPtr;

public:
    ScopedRAII(int *);
    ~ScopedRAII();
    int &operator*() const;  /* *raii retrieves data T& */
    int* operator->() const; /* raii> accesses data T* */

private:
    // Make these private so rule of 3 dont get fucked
    ScopedRAII(const int& );
    ScopedRAII & operator=(const int& );

};
