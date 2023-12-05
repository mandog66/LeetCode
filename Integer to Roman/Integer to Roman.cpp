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

using namespace std;

string intToRoman(int num)
{
    const int n = 4;
    vector<int> value(n);
    string s;
    unordered_map<int, char> roman = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};

    value[0] = num / 1000 * 1000;
    value[1] = (num % 1000) / 100 * 100;
    value[2] = (num % 100) / 10 * 10;
    value[3] = (num % 10) / 1 * 1;

    for (int i = 0; i < n; i++)
    {
        if (value[i] == 0)
            continue;

        if (roman[value[i]])
        {
            s.push_back(roman[value[i]]);
        }
        else
        {
            switch (i)
            {
            case 0:
                for (int j = 0; j < value[0] / 1000; j++)
                    s.push_back(roman[1000]);
                break;
            case 1:
                if (value[1] == 900)
                {
                    s.push_back('C');
                    s.push_back('M');
                }
                else if (value[1] == 400)
                {
                    s.push_back('C');
                    s.push_back('D');
                }
                else if (value[1] > 500)
                {
                    s.push_back('D');
                    for (int j = 0; j < (value[1] - 500) / 100; j++)
                        s.push_back('C');
                }
                else
                {
                    for (int j = 0; j < value[1] / 100; j++)
                        s.push_back('C');
                }
                break;
            case 2:
                if (value[2] == 90)
                {
                    s.push_back('X');
                    s.push_back('C');
                }
                else if (value[2] == 40)
                {
                    s.push_back('X');
                    s.push_back('L');
                }
                else if (value[2] > 50)
                {
                    s.push_back('L');
                    for (int j = 0; j < (value[2] - 50) / 10; j++)
                        s.push_back('X');
                }
                else
                {
                    for (int j = 0; j < value[2] / 10; j++)
                        s.push_back('X');
                }
                break;
            case 3:
                if (value[3] == 9)
                {
                    s.push_back('I');
                    s.push_back('X');
                }
                else if (value[3] == 4)
                {
                    s.push_back('I');
                    s.push_back('V');
                }
                else if (value[3] > 5)
                {
                    s.push_back('V');
                    for (int j = 0; j < value[3] - 5; j++)
                        s.push_back('I');
                }
                else
                {
                    for (int j = 0; j < value[3]; j++)
                        s.push_back('I');
                }
                break;
            }
        }
    }
    return s;
}

int main()
{
    int num = 3;
    cout << intToRoman(num) << endl; // return III
    num = 58;
    cout << intToRoman(num) << endl; // return LVIII
    num = 1994;
    cout << intToRoman(num) << endl; // return MCMXCIV
    num = 1695;
    cout << intToRoman(num) << endl; // return MDCXCV
    num = 20;
    cout << intToRoman(num) << endl; // return XX
}
