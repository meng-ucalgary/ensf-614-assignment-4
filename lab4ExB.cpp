#include <vector>
#include <string>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

typedef vector<string> String_Vector;

String_Vector transpose(const String_Vector &sv);
// REQUIRES:
//    sv.size() >= 1
//    All the strings in sv are the same length, and that length is >= 1.
// PROMISES:
//    Return value is the "transpose" of sv, as defined in the Exercise B
//    instructions.

int main()
{
    const int ROWS = 5;
    const int COLS = 4;

    char c = 'A';
    String_Vector sv;
    sv.resize(ROWS);

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
        {
            sv.at(i).push_back(c);
            c++;
            if (c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }

    for (int i = 0; i < ROWS; i++)
    {
        cout << sv.at(i);
        cout << endl;
    }
    cout << endl;
    String_Vector vs = transpose(sv);
    for (int i = 0; i < (int)vs.size(); i++)
        cout << vs.at(i) << endl;

    return 0;
}

String_Vector transpose(const String_Vector &sv)
{
    int rows = sv.size();
    int cols = sv.at(0).size();

    // create a new vector with cols size
    String_Vector vs(cols);

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            // get the character from transpose location: basically i and j reversed
            char c = sv.at(j).at(i);

            vs.at(i).push_back(c);
        }
    }

    return vs;
}
