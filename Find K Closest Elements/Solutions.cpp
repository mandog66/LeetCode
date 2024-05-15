#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using std::priority_queue;
using std::vector;

std::ostream &operator<<(std::ostream &os, const vector<int> &nums)
{
    os << "[";

    for (int i = 0; i < nums.size(); i++)
    {
        os << nums[i] << (i != nums.size() - 1 ? ", " : "");
    }

    os << "]";

    return os;
}

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    // watch solution video : https://www.youtube.com/watch?v=o-YDQzHoaKM and https://www.youtube.com/watch?v=gfwLpRYbCx0

    // size of window(k)
    int l = 0;
    int r = arr.size() - k;

    while (l < r)
    {
        // 我們的目的是找到有效最左值，這樣就只要加上 k 就是答案。
        //  m 就是起始點，假設最左值是它。
        int m = (l + r) / 2;

        if (arr[m + k] - x < x - arr[m])
            // m + k 到目標的距離 小於 m 到目標距離
            // 表示"右邊"也就是到 k 的值是比 m 還靠近目標
            // 那我們就靠右
            // m + 1 表示至少前 m 個的元素不會比 m + k 更靠近(更靠左或更靠右都是遠離目標)
            l = m + 1;
        else
            // m + k 到目標的距離 大於 m 到目標距離
            // 表示"左邊"也就是到 k 的值是比 m 還靠近目標
            // 那我們就靠左
            // 不設成 m - 1 是因為 m 還是有可能是答案
            r = m;
    }

    return vector<int>(arr.begin() + l, arr.begin() + (l + k));

    /************************************** Min Heap ver. **************************************/

    // pair<與 x 的距離差, 在 arr 中的值>
    // priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     pq.push(std::make_pair(std::abs(x - arr[i]), arr[i]));
    // }

    // vector<int> res;

    // for (int i = 0; i < k; i++)
    // {
    //     res.push_back(pq.top().second);
    //     pq.pop();
    // }

    // std::sort(res.begin(), res.end());

    // return res;

    /************************************** Min Heap ver. **************************************/
}

int main(int argc, char *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5};
    std::cout << findClosestElements(arr, 3, 3) << std::endl;

    arr = {1, 2, 3, 4, 5};
    std::cout << findClosestElements(arr, 4, -1) << std::endl;

    arr = {1, 1, 1, 7, 8, 10, 12, 13};
    std::cout << findClosestElements(arr, 3, 9) << std::endl;

    arr = {-2, -1, 1, 2, 3, 4, 5};
    std::cout << findClosestElements(arr, 7, 3) << std::endl;
}