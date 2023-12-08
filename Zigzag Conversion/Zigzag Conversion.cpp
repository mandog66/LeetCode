#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <cstdlib>
#include <time.h>
#include <unordered_map>
#include <array>
#include <stack>
#include <sstream>

using namespace std;

string convert(string s, int numRows)
{
    string word = "";
    string res = "";

    if (s.size() == 1)
        return s;

    int index = 0;

    while (index < s.size())
    {
        string wordLine = "";
        for (int i = 0; i < numRows && index < s.size(); i++)
        {
            wordLine += s[index++];
        }

        if (wordLine.size() < numRows)
        {
            while (wordLine.size() != numRows)
            {
                wordLine += ' ';
            }
        }

        word += wordLine;

        string wordReverse = "";
        for (int i = 0; i < numRows && index < s.size(); i++)
        {
            if (i == 0 || i == numRows - 1)
            {
                wordReverse += " ";
            }
            else
                wordReverse += s[index++];
        }

        if (wordReverse.size() < numRows)
        {
            while (wordReverse.size() != numRows)
            {
                wordReverse += ' ';
            }
        }

        reverse(wordReverse.begin(), wordReverse.end());
        word += wordReverse;
    }

    for (int i = 0; i < numRows; i++)
    {
        int index = i;
        while (index < word.size())
        {
            if (word[index] != ' ')
                res += word[index];
            index += numRows;
        }
    }

    return res;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << convert(s, numRows) << endl; // return "PAHNAPLSIIGYIR"

    string s1 = "PAYPALISHIRING";
    int numRows1 = 4;
    cout << convert(s1, numRows1) << endl; // return "PINALSIGYAHRPI"

    string s2 = "A";
    int numRows2 = 1;
    cout << convert(s2, numRows2) << endl; // return "A"

    string s3 = "ABCD";
    int numRows3 = 3;
    cout << convert(s3, numRows3) << endl; // return "ABDC"

    string s4 = "ABCDE";
    int numRows4 = 4;
    cout << convert(s4, numRows4) << endl; // return "ABCED"

    string s5 = "ABCDEF";
    int numRows5 = 5;
    cout << convert(s5, numRows5) << endl; // return "ABCDFE"
}
