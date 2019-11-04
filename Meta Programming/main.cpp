#include <iostream>
#include "Binary.hpp"
#include "TypeList.hpp"
#include "IsSame.hpp"
#include "Contains.hpp"
#include "AtIndex.hpp"
#include "PrintIT.hpp"

int main()
{
    //Binary
    std::cout << Binary<10101>::value << std::endl;

    std::cout << "IsSame <int , int >:: value=" << IsSame<int, int>::value << std::endl;
    /* Must be false */
    std::cout << "IsSame <int , char >:: value=" << IsSame<int, char>::value << std ::endl;

    typedef TYPELIST4(int, char, bool, double) MyTypeList;

    std::cout << Contains<MyTypeList, std::string>::value << std::endl;

    std::cout << Contains<MyTypeList, bool>::value << std::endl;

    // Assert index 0 is a int
    std::cout << "IsSame <typename AtIndex <TL , 0>::type , int >:: value = " << 
         IsSame<typename AtIndex<MyTypeList, 0>::Type, int>::value << std::endl;

    // Assert index 1 is a char
    std::cout << "IsSame <typename AtIndex <TL , 1>::type , char >:: value = " << 
         IsSame<typename AtIndex<MyTypeList, 1>::Type, char>::value << std::endl;
    
    // Assert index 2 is not a char
    std::cout << "IsSame <typename AtIndex <TL , 2>::type , char >:: value = " << 
         IsSame<typename AtIndex<MyTypeList, 2>::Type, char>::value << std::endl;     
       
    // Assert index 4 (last) is a NullType
    std::cout << "IsSame <typename AtIndex <TL , 4>::type , NullType >:: value = " << 
         IsSame<typename AtIndex<MyTypeList, 4>::Type, NullType>::value << std::endl;   
    
     // Assert index 60 is outOfBounce
    std::cout << "IsSame <typename AtIndex <TL , 60>::type , NullType >:: value = " << 
         IsSame<typename AtIndex<MyTypeList, 60>::Type, NullType>::value << std::endl;  
    
    std::cout << "PrintIt<TL>::value should(int, char, bool, double) -> " << PrintIT<MyTypeList>::value << std::endl;




    getchar();
}