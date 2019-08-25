#include "scopedRAII.hpp"

ScopedRAII::ScopedRAII(int *scopedPtr)
{
    _intPtr = scopedPtr;
}

ScopedRAII::~ScopedRAII()
{
    delete _intPtr;
}

int &ScopedRAII::operator*() const
{
    return *_intPtr;
}

int *ScopedRAII::operator->() const
{
    return _intPtr;
}