#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <string>

using std::priority_queue;
using std::string;
using std::unordered_set;
using std::vector;

// watch solution video : https://www.youtube.com/watch?v=WHfljqX61Y8
int smallestDistancePair(vector<int> &nums, int k, string s)
{
    if (s == "Brute Force")
    {
        /******************** Brute Force ********************/
        std::sort(nums.begin(), nums.end());
        const int N = nums.back();
        const int n = nums.size();
        vector<int> count(N + 1, 0);

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ++count[nums[j] - nums[i]];
            }
        }

        for (int i = 0; i < N; i++)
        {
            k -= count[i];

            if (k <= 0)
            {
                return i;
            }
        }

        return 0;
        /******************** Brute Force ********************/
    }
    else if (s == "Binary Search + DP")
    {
        /***************** Binary Search + DP *****************/
        /*
            使用 Binary Search 找到目標(m)，目標是"找到 <= m 距離的組合個數"
            而我們的搜索空間是所有可能的距離，例如 :
                nums = [1, 1, 3, 9]
                nums[3] - nums[0] = 8
                so search space is 0 ~ 8
                Left is 0 and Right is 8 and 4 is Mid
            然後找每個組合的距離，如果距離小於等於 M ，代表距離在 M 之前有的組合個數，
            將所有組合個數相加就是 "在 <= M 距離有的組合個數(count)"，接著與 k 比較，
            如果 count >= k ，表示 search space 太大，要縮小範圍，反之。
            最後就會縮在目標位置(k)上。
        */
        std::sort(nums.begin(), nums.end());

        int l = 0;                          // smallest distance
        int r = nums.back() - nums.front(); // largest distance
        const int n = nums.size();

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int count = 0; // number of the pair
            int j = 0;     // second number of the pair

            for (int i = 0; i < n; i++)
            {
                // i is first number of the pair
                while (j < n && nums[j] - nums[i] <= m)
                {
                    // j 可以不用一直初始化的原因是
                    // 當我們已經與 i 計算過距離後 i 會往前，這樣與 j 的距離只會更近，也就是距離一定是 <= m。
                    // 1    1   3   9        -->         1   1   3   9
                    // i            j                        i       j
                    //
                    // 9 index is 3 and 1 index is 1
                    // 3 - 1 - 1 = 1
                    // so when i is 1 the number of pair is 1
                    // j is not move
                    j++;
                }

                // 計算個數是利用 index 的距離差
                // 減 1 是要減去 j 當下的自己
                // 1    1   3   9
                // i            j
                // m = 4, there are 2 pair when less than or equal to 4
                // 9 index is 3 and 1 index is 0, so 3 - 1 - 1(j iteslf)
                count += (j - i - 1);
            }

            if (count >= k)
                // 大於 k 表示範圍太大
                // 等於 是說明可能有更小的距離也可以達到目標個數(k)，最後 m 會收斂到目標個數
                // said above 4 is mid but have no pair is equal to 4 and count is 3
                // this mean is less than 4 have same count(answer is 2)
                r = m - 1;
            else
                // 反之
                l = m + 1;
        }

        return l;
        /***************** Binary Search + DP *****************/
    }
    else
        std::cout << "Not done" << std::endl;

    return -1;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 1, 3, 9};
    int k = 3;
    std::cout << smallestDistancePair(nums, k, "Brute Force") << std::endl;        // 2
    std::cout << smallestDistancePair(nums, k, "Binary Search + DP") << std::endl; // 2
}