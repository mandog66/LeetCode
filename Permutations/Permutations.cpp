#include <iostream>
#include <vector>

using std::vector;

void helper(vector<int> nums, vector<int> combine, vector<bool> visited, vector<vector<int>> &res)
{
    if (combine.size() == nums.size())
    {
        res.push_back(combine);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i])
            continue;

        combine.push_back(nums[i]);
        visited[i] = true;

        helper(nums, combine, visited, res);

        combine.pop_back();
        visited[i] = false;
    }

    return;
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<bool> visited(nums.size(), false);
    vector<vector<int>> res;

    helper(nums, {}, visited, res);

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {0, 1};
    vector<int> nums3 = {1};

    vector<vector<int>> res = permute(nums1);

    std::cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << (i == 0 ? "[" : ", [");
        for (int j = 0; j < res[0].size(); j++)
            std::cout << (j == 0 ? "" : ", ") << res[i][j];
        std::cout << "]";
    }
    std::cout << "]" << std::endl;

    res = permute(nums2);

    std::cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << (i == 0 ? "[" : ", [");
        for (int j = 0; j < res[0].size(); j++)
            std::cout << (j == 0 ? "" : ", ") << res[i][j];
        std::cout << "]";
    }
    std::cout << "]" << std::endl;

    res = permute(nums3);

    std::cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << (i == 0 ? "[" : ", [");
        for (int j = 0; j < res[0].size(); j++)
            std::cout << (j == 0 ? "" : ", ") << res[i][j];
        std::cout << "]";
    }
    std::cout << "]" << std::endl;
}