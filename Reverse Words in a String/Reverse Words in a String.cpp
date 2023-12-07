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

string reverseWords(string s)
{
    vector<string> word;

    int head = 0;
    int tail = s.size() - 1;

    while (s[head] == ' ' || s[tail] == ' ')
    {
        if (s[head] == ' ')
        {
            s.erase(head, 1);
            tail--;
        }

        if (s[tail] == ' ')
        {
            s.erase(tail, 1);
            tail--;
        }
    }

    int n = s.size();
    string clip = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            clip += s[i];
            if (i == n - 1)
                word.push_back(clip);
        }
        else
        {
            if (clip != "")
            {
                word.push_back(clip);
                clip = "";
            }
        }
    }

    string res = "";
    n = word.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        res += word[i];
        if (i != 0)
            res += " ";
    }

    return res;
}

int main()
{
    string s = {"the sky is blue"};
    cout << reverseWords(s) << endl; // return "blue is sky the"

    s = {"  hello world  "};
    cout << reverseWords(s) << endl; // return "world hello"

    s = {"a good   example"};
    cout << reverseWords(s) << endl; // return "example good a"
}
