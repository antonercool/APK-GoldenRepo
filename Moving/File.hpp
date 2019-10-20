#pragma once
#include <string>
#include <stdio.h>
#include <iostream>

namespace FileReader
{
class File
{

private:
    FILE *_file;

public:
    // Opens the file, with  read/write permissions
    File(const std::string &file_path)
    {
        _file = fopen(file_path.c_str(), "a+");

        if (_file == nullptr)
        {
            std::cout << "Specified file not found" << std::endl;
        }
    }

    File(FileReader::File &&fileToShallowClone)
    {
        //Steal resource from fileToShallowClone
        this->_file = fileToShallowClone._file;
        fileToShallowClone._file = nullptr;
    }

    // Close the file
    ~File()
    {
        if (_file != nullptr)
        {
            fclose(_file);
            std::cout << "leasing resources" << std::endl;
        }
        std::cout << "resources is empty, has been moved " << std::endl;
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
};
} // namespace FileReader
