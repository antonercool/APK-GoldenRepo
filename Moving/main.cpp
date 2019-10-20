#include <iostream>
#include <string>
#include "File.hpp"


int main(){

    FileReader::File myTestFile("test.txt");

    std::string first8chars = myTestFile.readLine();
    std::cout << first8chars << std::endl;

    myTestFile.readLine("Du er pisse grim");
    
    return 0;

}