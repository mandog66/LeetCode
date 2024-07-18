#include <iostream>
#include <vector>

using std::vector;

void helper(vector<int> &nums, vector<vector<int>> &res, int idx)
{
    if (idx == nums.size() - 1)
    {
        res.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        std::swap(nums[idx], nums[i]);
        helper(nums, res, idx + 1);
        std::swap(nums[i], nums[idx]);
    }

    return;
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    helper(nums, res, 0);
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