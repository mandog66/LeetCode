#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using std::priority_queue;
using std::unordered_set;
using std::vector;

int smallestDistancePair(vector<int> &nums, int k)
{
    // int res = INT_MAX;
    // vector<int> dis;

    // for (int i = 0; i < nums.size() - 1; i++)
    // {
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         dis.push_back(std::abs(nums[i] - nums[j]));
    //     }
    // }

    // std::sort(dis.begin(), dis.end());
    // return dis[k - 1];

    priority_queue<int, vector<int>, std::greater<int>> pq;
    unordered_set<int> visited;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int n = std::abs(nums[i] - nums[j]);

            if (visited.find(n) == visited.end())
            {
                pq.push(n);
                visited.insert(n);
            }
        }
    }

    while (k - 1 > 0)
    {
        pq.pop();
        k--;
    }

    return pq.top();
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 1, 3, 9};
    int k = 3;
    std::cout << smallestDistancePair(nums, k) << std::endl; // 0
}