#pragma once
#include "TypeList.hpp"
#include <string>

template<typename TL>
struct PrintIT
{   
    inline static const std::string value = typeid(typename TL::First).name() + std::string(", ") + PrintIT<typename TL::Rest>::value;
};

template<>
struct PrintIT<NullType>
{
    inline static const std::string value = "";
};

