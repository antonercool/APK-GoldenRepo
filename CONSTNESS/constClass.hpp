#pragma once


class ConstClass
{
private:
    int data;
public:
    ConstClass(int);
    

    void printDataConst() const;
    void printData();

};

