#pragma once

#define TYPELIST1(arg1) TypeList<arg1, NullType>
#define TYPELIST2(arg1, arg2) TypeList<arg1, TYPELIST1(arg2)>
#define TYPELIST3(arg1, arg2, arg3) TypeList<arg1, TYPELIST2(arg2, arg3)>
#define TYPELIST4(arg1, arg2, arg3, arg4) TypeList<arg1, TYPELIST3(arg2, arg3,arg4)>

struct NullType{};
template <typename L, typename R>
struct TypeList
{
    typedef L First;
    typedef R Rest;
};







