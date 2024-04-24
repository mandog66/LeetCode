#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::vector;

std::ostream &operator<<(std::ostream &os, const vector<int> &v)
{
    os << "[";

    for (int i = 0; i < v.size(); i++)
    {
        os << (i != 0 ? ", " : "") << v[i];
    }

    os << "]";

    return os;
}

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> res(temperatures.size(), 0);
    stack<int> s;

    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!s.empty() && temperatures[i] > temperatures[s.top()])
        {
            res[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    return res;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    std::cout << dailyTemperatures(temperatures) << std::endl; // [1, 1, 4, 2, 1, 1, 0, 0]

    temperatures = {30, 40, 50, 60};
    std::cout << dailyTemperatures(temperatures) << std::endl; // [1, 1, 1, 0]

    temperatures = {30, 60, 90};
    std::cout << dailyTemperatures(temperatures) << std::endl; // [1, 1, 0]
}
