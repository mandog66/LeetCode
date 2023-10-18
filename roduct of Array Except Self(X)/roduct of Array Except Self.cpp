/*
    I didn't get it.(See Solutions.cpp)

    It's fine!

    Keep going!
*/

#include <iostream>
#include <vector>

using namespace std;

void show_ans(const vector<int>);

void approach1(vector<int> &nums)
{
    const int n = nums.size();
    vector<int> ans(n);
    vector<int> left(n);
    vector<int> right(n);

    left[0] = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }

    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = left[i] * right[i];
    }

    show_ans(ans);
}

void approach2(vector<int> &nums)
{
    const int n = nums.size();
    vector<int> ans(n);

    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    int right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = ans[i] * right;
        right = right * nums[i];
    }

    show_ans(ans);
}

void show_ans(const vector<int> nums)
{
    for (auto it = nums.begin(); it != nums.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    vector<int> ex1 = {1, 2, 3, 4};
    vector<int> ex2 = {-1, 1, 0, -3, 3};

    approach1(ex1);

    approach2(ex2);
}
