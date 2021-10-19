/*
 * File Name:                       lab4ExB.cpp
 * Course:                            ENSF 614 - Fall 2021
 * Lab # and Assignment #:  Lab 4 Exercise B
 * Lab section:                     B01
 * Completed by:                  Bhavyai Gupta, Aastha Patel
 * Submission Date:              NA
 */

#include<vector>
#include<string>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

typedef vector<string> String_Vector;

String_Vector transpose(const String_Vector& sv);
// REQUIRES:
//    sv.size() >= 1
//    All the strings in sv are the same length, and that length is >= 1.
// PROMISES:
//    Return value is the "transpose" of sv, as defined in the Exercise B
//    instructions.

int main() {

    const int ROWS = 5;
    const int COLS = 4;

    char c = 'A';
    String_Vector sv;

    sv.resize(ROWS);

     cout << endl;
     cout << "Given Matrix"<<endl;
     cout << endl;

    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++) {
            sv.at(i).push_back(c);
            c++;
            if(c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }

    for(int i = 0; i < ROWS; i++)
       {
                    cout<< sv.at(i);
                    cout << endl;
        }


     cout << endl;
     cout << "Transpose Matrix"<<endl;
     cout << endl;

    String_Vector sv1;
    String_Vector vs = transpose(sv1);

    for(int i = 0; i < (int)vs.size(); i++)
        cout << vs.at(i) << endl;

    return 0;
}



String_Vector transpose (const String_Vector& sv) {

    // STUDENTS MUST COMPLETE THE DEFINITION OF THIS FUNCTION.

    const int ROWS = 5;
    const int COLS = 4;

    char c = 'A';

     String_Vector sv1;
     sv1 = sv;
     sv1.resize(ROWS);

    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++) {
            sv1.at(j).push_back(c);
            c++;
            if(c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }

      return sv1;

}
