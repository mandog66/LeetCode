#include <iostream>
#include <vector>

using std::vector;

// watch solution video : https://www.youtube.com/watch?v=YUF3_eBdzsk

/*
    我們的目標是利用"binary search"找到結果。
    那我們的搜尋空間是什麼?題目要我們找出分成k個子陣列後加總的最大值是所有可能組合的最小值。
    所以我們的搜尋空間就是所有組合的加總。
*/
bool canSplit(vector<int> &nums, int k, int largest)
{
    // 計數總和在 largest 下，可能有的子陣列數量(最大值為 k)
    int subArray = 0;
    int curSum = 0;

    for (int n : nums)
    {
        curSum += n;

        if (curSum > largest)
        {
            /*
                subArray 加一表示已經存在一個子陣列了，接著從 n 重新開始加總，相當於找另一個子陣列。
                目標要記得是找到最小的加總(m = largest)，只要發現有小於等於的子陣列，不管如何就表示
                可能有更小的總和，切割只會讓子陣列加總更小，更加表示 m 有可能更小。
            */
            subArray++;
            curSum = n;
        }
    }

    /*
        subArray 的意思可以想成，如果 m = 12而且 k = 3，經過上面的計算 subArray = 3，
        subArray + 1 > k 表示要有比 m 更優的解需要的切割數。所以，要是為 True 表示在
        這個切割數量下可能有更優解，反之，要是為 False 表示在這個切割數量下不可能有更優解。
    */
    return subArray + 1 <= k;
}

int splitArray(vector<int> &nums, int k)
{
    /*
        這裡把左邊界設定成元素最大值的原因是 :
        元素只會大於等於0而且每個元素都有可能自己成為一個子陣列或是跟其他元素一起組成，
        那假設每個元素都自己當成一個子陣列，那最大元素就會是這個組合的最大值。
        不管如何最大元素自己當一個子陣列或是與其他元素一起，那就有可能是這個組合中的最大值。
    */
    int res = -1;

    int l = INT_MIN;
    for (int n : nums)
        l = std::max(l, n);

    // 右邊界就是所有元素的總和(不可能有更大值)
    int r = 0;
    for (int n : nums)
        r += n;

    while (l <= r)
    {
        /*
            這個 m 所代表的意思是有沒有可能在組合中找到小於等於 m 的值，
            如果有表示我們找到更好的結果。
            可是組合有很多個，那要怎麼找到正確的組合跟怎麼分割陣列?
            我們可以利用貪婪演算法找到。我們從第一個元素開始加總元素，
            如果元素總和小於 m，那就再加下一個元素，直到大於等於 m。
            當元素個數n + 1 總和大於等於 m，那在 n 個元素時就代表有更小的總和存在。
            但是 k 可能大於 2，這樣切只有兩個子陣列，怎麼辦?其實在元素個數 n 個時，
            就是小於 m 的極限，這樣的話繼續切割一定只會更小於 m，表示有可能有更好解。
        */
        int m = l + (r - l) / 2;

        if (canSplit(nums, k, m))
        {
            res = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 3;
    std::cout << splitArray(nums, k) << std::endl;
}