#pragma once
#include <string>
#include <stdio.h>
#include <iostream>

/*
Simplified definition of lvalue and rvalues
- lvaule - An object that occupies some identifiable location in memory
    - most values is c++ are lvalues
Example: 
int i;          // i is a lvalue
int* p = &i;    // u's address is identifiable
i = 2           // memoty content is modified



- rvalue - Any object that is not a lvalue (dont have a memlocation)
Example:

int i = 2           // i is a lvalue // 2 is a rvalue
int x = i +2        // (i + 2) is a rvalue
int* p = &(i + 2)   // error cant take address of rvalue
i + 2 = 4           // error -- Left side of the assignment operator must ALLWAYS be a lvalue
2  = i;             // error --   --|same ^|--                // right side can be rvalues and lvaues mixed 

Car c1;             // lvalue
c1 = Car();         // Car is a rvalue

int i = sum(2,4)    // sum(2,4) is a rvalue
*/

namespace FileReader
{
class File
{

private:
    FILE *_file = nullptr;
    std::string _filePath;

public:
    // Opens the file, with  read/write permissions
    File(const std::string &filePath)
    {
        std::cout << "File Constructor" << std::endl;
        _file = fopen(filePath.c_str(), "a+");
        _filePath = filePath;

        if (_file == nullptr)
        {
            std::cout << "Specified file not found" << std::endl;
        }
    }

    // CopyConstructor -- DeepCopy
    File(const File &otherToCopy)
    {
        std::cout << "CopyConstructor" << std::endl;
        _file = fopen(otherToCopy._filePath.c_str(), "a+");
        _filePath = otherToCopy._filePath;
    }

    // DeepAssignment
    File &operator=(const File &otherToCopyAssign)
    {

        std::cout << "CopyAssigmentOperator" << std::endl;

        if (this == &otherToCopyAssign)
        {
            return *this;
        }

        //Close this's currents file
        if (_file != nullptr)
        {
            fclose(_file);
        }
        // can to obects read to and write the the same file ?? YES
        _file = fopen(otherToCopyAssign._filePath.c_str(), "a+");
        _filePath = otherToCopyAssign._filePath;
        return *this;
    }

    // move constructor -- Shallow copy
    File(FileReader::File &&fileToShallowClone) noexcept
    {
        std::cout << "MoveConstrutor" << std::endl;
        //Steal resource from fileToShallowClone
        _file = fileToShallowClone._file;
        _filePath = fileToShallowClone._filePath;

        // When tempObject calls destructor if does not delete beacuse it is nullptr
        fileToShallowClone._file = nullptr;
        // std::swap(fileToShallowClone._file, this->_file)
    }

    //shallow Assignment
    File &operator=(File &&fileToShallowAssign) noexcept
    {
        std::cout << "MoveAssigment" << std::endl;
        // Self check
        if (&fileToShallowAssign == this)
        {
            return *this;
        }

        //close own
        if (_file != nullptr)
        {
            fclose(_file);
        }

        // steal other
        _file = fileToShallowAssign._file;
        _filePath = fileToShallowAssign._filePath;

        // clear other 
        fileToShallowAssign._file = nullptr;

        return *this;
    }

    // Important information about delete operation
    // delete performs the check anyway, so checking it on your side adds overhead and looks uglier.
    // A very good practice is setting the pointer to NULL after delete (helps avoiding double deletion and other similar memory corruption problems).

    // Close the file
    ~File()
    {
        // If it is nullptr the resource has been moved
        // Or the specified file was not found
        if (_file != nullptr)
        {
            fclose(_file);
            std::cout << "leasing resources" << std::endl;
        }
        else
        {
            std::cout << "resources is empty, has been moved or the specified file was not found" << std::endl;
        }
    }

    std::string readLine()
    {
        char buffer[255];
        fgets(buffer, 255, _file);

        //Overloaded assignment operator
        std::string stringFromFile = buffer;
        return stringFromFile;
    }

    void appendLine(std::string stringToAdd)
    {
        fputs(stringToAdd.c_str(), _file);
    }

    bool holdsReso()
    {
        if (_file == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
} // namespace FileReader
