#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &nums)
{
    const int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        out << nums[i] << " ";
    }

    return out;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, vector<int>> hashmap;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!hashmap.count(nums[i]))
        {
            hashmap.insert(make_pair(nums[i], vector<int>{i}));
        }
        else
        {
            hashmap[nums[i]].push_back(i);
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int num = target - nums[i];
        if (num == nums[i] && hashmap[num].size() > 1)
        {
            return hashmap[num];
        }
        else if (num == nums[i] && hashmap[num].size() < 2)
        {
            continue;
        }
        else if (hashmap.count(num) > 0)
        {
            hashmap[nums[i]].push_back(hashmap[num][0]);
            return hashmap[nums[i]];
        }
    }

    return vector<int>();
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    cout << twoSum(nums, 9) << endl;

    nums = {3, 2, 4};
    cout << twoSum(nums, 6) << endl;

    nums = {3, 3};
    cout << twoSum(nums, 6) << endl;
}
