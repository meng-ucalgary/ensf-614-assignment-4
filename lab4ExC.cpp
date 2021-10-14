/*
 * File Name:               lab4ExC.cpp
 * Course:                  ENSF 614 - Fall 2021
 * Lab # and Assignment #:  Lab 4 Exercise C
 * Lab section:             B01
 * Completed by:            Bhavyai Gupta, Aastha Patel
 * Submission Date:         NA
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>

const int size = 6;
using namespace std;
struct City
{
    double x, y;
    char name[30];
};

void write_binary_file(City cities[], int size, char *filename);
/* PROMISES: attaches an ofstream object to a binary file named "filename" and
 * writes the content of the array cities into the file.
 */

void print_from_binary(char *filename);
/* PROMISES: uses ifstream library object to open the binary file named
 * "filename", reads the content of the file which are objects of struct City
 * (one record at a time), and displays them on the screen. It also saves the records
 * into a text-file that its name must be the filename argument, but with the extension
 * of .txt
 */

int main()
{
    char bin_filename[] = "cities.bin";

    City cities[size] = {{100, 50, "Calgary"},
                         {100, 150, "Edmonton"},
                         {50, 50, "Vancouver"},
                         {200, 50, "Regina"},
                         {500, 50, "Toronto"},
                         {200, 50, "Montreal"}};

    write_binary_file(cities, size, bin_filename);
    cout << "\nThe content of the binary file is:" << endl;
    print_from_binary(bin_filename);
    return 0;
}

void write_binary_file(City cities[], int size, char *filename)
{
    ofstream stream(filename, ios::out | ios::binary);
    if (stream.fail())
    {
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < size; i++)
        stream.write((char *)&cities[i], sizeof(City));
    stream.close();
}

void print_from_binary(char *filename)
{
    ifstream in_stream(filename, ios::in | ios::binary);
    if (in_stream.fail())
    {
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }

    int length = strlen(filename);
    char *filename_txt = new char[length + 1];
    for (int i = 0; i < length - 3; i++)
    {
        filename_txt[i] = filename[i];
    }
    filename_txt[length - 3] = 't';
    filename_txt[length - 2] = 'x';
    filename_txt[length - 1] = 't';
    filename_txt[length] = '\0';

    ofstream out_stream(filename_txt);
    if(out_stream.fail())
    {
        cerr << "failed to open file: " << filename_txt << endl;
        exit(1);
    }

    City c;
    while (!in_stream.eof())
    {
        in_stream.read((char *)&c, sizeof(City));
        cout << "Name: " << c.name << ", x coordinate: " << c.x << ", y coordinate: " << c.y << endl;
        out_stream << "Name: " << c.name << ", x coordinate: " << c.x << ", y coordinate: " << c.y << endl;
    }

    in_stream.close();
    out_stream.close();
    delete[] filename_txt;
}
