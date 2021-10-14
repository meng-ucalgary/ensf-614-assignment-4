/*
 * File Name:               MyArray.cpp
 * Course:                  ENSF 614 - Fall 2021
 * Lab # and Assignment #:  Lab 4 Exercise A
 * Lab section:             B01
 * Completed by:            Bhavyai Gupta, Aastha Patel
 * Submission Date:         NA
 */

#include "MyArray.h"

MyArray::MyArray()
{
    sizeM = 0;
    storageM = new EType[sizeM];
}

MyArray::MyArray(const EType *builtin, int sizeA)
{
    sizeM = sizeA;
    storageM = new EType[sizeM];

    for (int i = 0; i < sizeA; i++)
    {
        storageM[i] = builtin[i];
    }
}

MyArray::MyArray(const MyArray &source)
{
    sizeM = source.size();
    storageM = new EType[sizeM];

    for (int i = 0; i < sizeM; i++)
    {
        storageM[i] = source.storageM[i];
    }
}

MyArray &MyArray::operator=(const MyArray &rhs)
{
    if (this != &rhs)
    {
        delete[] storageM;
        sizeM = rhs.size();
        storageM = new EType[sizeM];

        for (int i = 0; i < sizeM; i++)
        {
            storageM[i] = rhs.storageM[i];
        }
    }

    return *this;
}

MyArray::~MyArray()
{
    delete[] storageM;
    storageM = nullptr;
}

int MyArray::size() const
{
    return sizeM;
}

EType MyArray::at(int i) const
{
    return storageM[i];
}

void MyArray::set(int i, EType new_value)
{
    storageM[i] = new_value;
}

void MyArray::resize(int new_size)
{
    EType *temp = new EType[new_size];

    int limit = (new_size > sizeM) ? new_size : sizeM;

    for (int i = 0; i < limit; i++)
    {
        temp[i] = storageM[i];
    }

    delete[] storageM;
    sizeM = new_size;
    storageM = temp;
}