#include <iostream>
#include <string>
#include "File.hpp"

using namespace FileReader;

int main()
{
    // Test Constructor -- Copy -- Assignment
    std::cout << "Test Constructor -- Copy -- Assignment" << std::endl;
    { // constructor
        File myFile1("test.txt");
        File myFile2("test2.txt");

        //CopycConstructor
        File myFile3(myFile1);

        std::string firstLine = myFile1.readLine();
        std::string firstLine1 = myFile3.readLine();

        std::cout << firstLine << std::endl;
        std::cout << firstLine1 << std::endl;

        // Assignment
        myFile2.appendLine("Musko");
        // Should now use "Text2.txt"
        myFile1 = myFile2;

        // Should write "Musko"
        std::cout << myFile1.readLine() << std::endl;
    }

    std::cout << std::endl;

    // Testing Move semanticts
    std::cout << "Testing copy Move Semantics" << std::endl;
    {
        // File("test2.txt") is a rvalue
        File myFile1(std::move(File("test2.txt")));
        //File myFile1(File{"test2.txt"});
        ///File myFile1(File("test2.txt"));

        std::cout << myFile1.readLine() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Testing assignment Move Semantics" << std::endl;
    {
        File myFile1("test.txt");

        std::cout << myFile1.readLine() << std::endl;

        //myFile1 = std::move(File("test2.txt"));
        myFile1 = File("Test.txt");
        //myFile1 = File{"test2.txt"};

        std::cout << myFile1.readLine() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Testing valid move" << std::endl;
    {
        File myFile1("test.txt");
        File myFile2("test2.txt");

        std::cout << myFile1.readLine() << std::endl;

        myFile1 = std::move(myFile2);

        if (!myFile2.holdsReso())
        {
            std::cout << "File was succesfully moved" << std::endl;
        }
        
        std::cout << myFile1.readLine() << std::endl;
    }

    getchar();

    return 0;
}