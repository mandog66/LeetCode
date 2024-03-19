#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dominantIndex(vector<int> &nums)
{
    const int size = nums.size();

    vector<int> temp(size);
    copy(nums.begin(), nums.end(), temp.begin());
    sort(temp.begin(), temp.end());

    int largest = temp[size - 1];
    if (largest >= temp[size - 2] * 2)
    {
        auto it = find(nums.begin(), nums.end(), largest);

        // it in the nums
        if (it != nums.end())
        {
            // calculate index
            int index = it - nums.begin();
            return index;
        }
        else
            return -1;
    }
    else
    {
        return -1;
    }

    return 0;
}

int main()
{
    vector<int> nums2 = {3, 6, 1, 0};
    vector<int> nums3 = {1, 2, 3, 4};

    cout << dominantIndex(nums2) << endl; // return 1
    cout << dominantIndex(nums3) << endl; // return -1
}
