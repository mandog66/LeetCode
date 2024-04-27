#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <cmath>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::unordered_set;
using std::vector;

string calculate(int num1, int num2, string token)
{
    if (token == "+")
    {
        return std::to_string(num1 + num2);
    }
    else if (token == "-")
    {
        return std::to_string(num1 - num2);
    }
    else if (token == "*")
    {
        return std::to_string(num1 * num2);
    }
    else if (token == "/")
    {
        return std::to_string(num1 / num2);
    }

    return "Not Find Token";
}

int string2int(string num)
{
    int _pow = 0;
    long int res = 0;
    for (auto idx = num.rbegin(); idx != num.rend(); idx++)
    {
        if ((*idx) != '-')
            res += (std::pow(10, _pow++) * (*idx - '0'));
        else
        {
            res *= (-1);
        }
    }

    return res;
}

int evalRPN(vector<string> &tokens)
{
    unordered_set<string> offset = {"+", "-", "*", "/"};
    stack<string> s;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (offset.find(tokens[i]) != offset.end())
        {
            long int num1 = string2int(s.top());
            s.pop();
            long int num2 = string2int(s.top());
            s.pop();
            s.push(calculate(num2, num1, tokens[i]));
        }
        else
        {
            s.push(tokens[i]);
        }
    }

    return string2int(s.top());
}

int main()
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens) << endl; // 9

    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens) << endl; // 6

    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens) << endl; // 22
}
