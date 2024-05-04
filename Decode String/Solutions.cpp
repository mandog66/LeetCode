#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::string;

/**************************Solution 1 recursion ver.**************************/
string recursion(string s, int &idx)
{
    int n = 0;
    string res = "";

    while (idx < s.size())
    {
        if (isdigit(s[idx]))
        {
            // s[idx] is a digit
            n = n * 10 + stoi(std::to_string(s[idx] - '0'));
        }
        else if (s[idx] == '[')
        {
            // s[idx] is a [
            string word = recursion(s, ++idx);

            while (n > 0)
            {
                res += word;
                n--;
            }
        }
        else if (s[idx] == ']')
        {
            // s[idx] is a ]
            return res;
        }
        else
        {
            // s[idx] is the alone letters
            res.push_back(s[idx]);
        }

        idx++;
    }

    return res;
}

string decodeString_Recursion(string s)
{
    int idx = 0;

    return recursion(s, idx);
}
/**************************Solution 1 recursion ver.**************************/

/**************************Solution 2 stack ver.**************************/
string decodeString_Stack(string s)
{
    stack<char> stack;

    for (int idx = 0; idx < s.size(); idx++)
    {
        if (s[idx] != ']')
        {
            stack.push(s[idx]);
        }
        else
        {
            string word = "";
            while (stack.top() != '[')
            {
                word = stack.top() + word;
                stack.pop();
            }

            stack.pop(); // for '['

            string time = "";
            while (!stack.empty() && isdigit(stack.top()))
            {
                time = stack.top() + time;
                stack.pop();
            }

            int times = stoi(time);
            while (times--)
            {
                for (int idx_c = 0; idx_c < word.size(); idx_c++)
                {
                    stack.push(word[idx_c]);
                }
            }
        }
    }

    string res = "";
    while (!stack.empty())
    {
        res = stack.top() + res;
        stack.pop();
    }

    return res;
}
/**************************Solution 2 stack ver.**************************/

int main()
{
    string s = "3[a]2[bc]";
    std::cout << decodeString_Recursion(s) << std::endl; // aaabcbc

    s = "3[a2[c]]";
    std::cout << decodeString_Recursion(s) << std::endl; // accaccacc

    s = "2[abc]3[cd]ef";
    std::cout << decodeString_Recursion(s) << std::endl; // abcabccdcdcdef

    s = "3[a]2[bc]";
    std::cout << decodeString_Stack(s) << std::endl; // aaabcbc

    s = "3[a2[c]]";
    std::cout << decodeString_Stack(s) << std::endl; // accaccacc

    s = "2[abc]3[cd]ef";
    std::cout << decodeString_Stack(s) << std::endl; // abcabccdcdcdef
}