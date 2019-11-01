#pragma once
#include<cstddef>

template <size_t N>
struct IsBinary{};

template <>
struct IsBinary<0>
{
    static const size_t value = 0;
};

template<>
struct IsBinary<1>
{
    static const size_t value = 1;
};

template <size_t N>
struct Binary
{
    static const size_t value = Binary <N/10 >:: value << 1 | IsBinary<N%10>::value;
};

template <>
struct Binary <0>
{
    static const size_t value = 0;
};