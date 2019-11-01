#pragma once
#include "TypeList.hpp"

// AtIndex<TypeList, 2>
//Generalized
template<typename TL, unsigned int Index>
struct AtIndex
{
    typedef typename AtIndex<typename TL::Rest, Index-1>::Type Type; 
};

//FullySpecialized for indexes == 0;
template <typename TL>
struct AtIndex<TL, 0>
{
    typedef typename TL::First Type;
};

//FUllySpecialized for TL == NullType
// LastIndex is Nultype
template<>
struct AtIndex<NullType,0>
{
    typedef NullType Type;
};

// Overflow
// Fx: AtIndex<TL, 5454>
template<unsigned int Index>
struct AtIndex<NullType, Index>
{
    typedef NullType Type;
};




