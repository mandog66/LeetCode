#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> res;
    int lIdx = 0, rIdx = 0;
    while (lIdx < left.size() && rIdx < right.size())
    {
        if (left[lIdx] <= right[rIdx])
        {
            res.push_back(left[lIdx]);
            lIdx++;
        }
        else
        {
            res.push_back(right[rIdx]);
            rIdx++;
        }
    }

    if (lIdx < left.size())
    {
        for (int i = lIdx; i < left.size(); i++)
            res.push_back(left[i]);
    }
    else
    {
        for (int i = rIdx; i < right.size(); i++)
            res.push_back(right[i]);
    }

    return res;
}

vector<int> sortArray(vector<int> &nums)
{
    // Top-down Approach(Divide-and-Conquer)
    // if (nums.size() <= 1)
    //     return nums;

    // const int n = nums.size() - 1;
    // int mid = n / 2;
    // vector<int> left(nums.begin(), nums.begin() + mid + 1);
    // left = sortArray(left);
    // vector<int> right(nums.begin() + mid + 1, nums.end());
    // right = sortArray(right);

    // return merge(left, right);

    // Bottom-up Approach(Iterative)
    queue<vector<int>> todo;
    for (int i = 0; i < nums.size(); i++)
        todo.push({nums[i]});

    while (todo.size() > 1)
    {
        vector<int> left = todo.front();
        todo.pop();
        vector<int> right = todo.front();
        todo.pop();

        int l = 0, r = 0, k = 0;
        vector<int> temp(left.size() + right.size(), 0);
        while (l < left.size() && r < right.size())
        {
            if (left[l] <= right[r])
                temp[k++] = left[l++];
            else
                temp[k++] = right[r++];
        }

        while (l < left.size())
            temp[k++] = left[l++];

        while (r < right.size())
            temp[k++] = right[r++];

        todo.push(temp);
    }

    return todo.front();
}

int main(int argc, char *argv[])
{
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    // vector<int> nums = {1, 2, 0};

    nums = sortArray(nums);

    std::cout << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << (i != 0 ? ", " : "") << nums[i];
    }
    std::cout << "]" << std::endl;
}