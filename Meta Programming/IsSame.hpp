#pragma once
template <typename type1, typename type2>
struct IsSame
{
    static const bool value = false;
};



template <typename type1>
class IsSame<type1, type1>
{
public:
    static const bool value = true;
};