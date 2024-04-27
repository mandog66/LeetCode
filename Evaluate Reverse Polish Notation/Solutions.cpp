#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <functional>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

int evalRPN(vector<string> &tokens)
{
    /*********** Solution 1 ***********/
    // stack<int> numbers;

    // for (const string &token : tokens)
    // {
    //     if (token.size() > 1 || isdigit(token[0]))
    //     {
    //         numbers.push(stoi(token));
    //     }
    //     else
    //     {
    //         int operand2 = numbers.top();
    //         numbers.pop();

    //         int operand1 = numbers.top();
    //         numbers.pop();

    //         switch (token[0])
    //         {
    //         case '+':
    //             numbers.push(operand1 + operand2);
    //             break;
    //         case '-':
    //             numbers.push(operand1 - operand2);
    //             break;

    //         case '*':
    //             numbers.push(operand1 * operand2);
    //             break;

    //         case '/':
    //             numbers.push(operand1 / operand2);
    //             break;
    //         }
    //     }
    // }

    // return numbers.top();
    /*********** Solution 1 ***********/

    /*********** Solution 2 ***********/
    unordered_map<string, std::function<int(int, int)>> map = {
        {"+", [](int a, int b)
         { return a + b; }},
        {"-", [](int a, int b)
         { return a - b; }},
        {"*", [](int a, int b)
         { return a * b; }},
        {"/", [](int a, int b)
         { return a / b; }}};

    stack<int> stack;

    for (string &s : tokens)
    {
        if (!map.count(s))
        {
            stack.push(stoi(s));
        }
        else
        {
            int op1 = stack.top();
            stack.pop();
            int op2 = stack.top();
            stack.pop();
            stack.push(map[s](op2, op1));
        }
    }

    return stack.top();
    /*********** Solution 2 ***********/
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
