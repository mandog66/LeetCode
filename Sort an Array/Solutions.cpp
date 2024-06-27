#include <iostream>
#include <vector>

using std::vector;

void merge(vector<int> &nums, int low, int mid, int high)
{
    if (low >= high)
        return;

    int l = low, r = mid + 1, k = 0, n = high - low + 1;
    vector<int> sorted(n, 0);

    while (l <= mid && r <= high)
        sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];

    while (l <= mid)
        sorted[k++] = nums[l++];

    while (r <= high)
        sorted[k++] = nums[r++];

    for (k = 0; k < n; k++)
        nums[k + low] = sorted[k];
}

void sortArray(vector<int> &nums, int low, int high)
{
    // Top-down Approach(Divide-and-Conquer)
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    sortArray(nums, low, mid);
    sortArray(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

int main(int argc, char *argv[])
{
    vector<int> nums = {5, 1, 1, 2, 0, 0};

    sortArray(nums, 0, nums.size() - 1);

    std::cout << "[";
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << (i != 0 ? ", " : "") << nums[i];
    }
    std::cout << "]" << std::endl;
}