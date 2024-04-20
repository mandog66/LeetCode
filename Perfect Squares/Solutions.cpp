#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::min;
using std::queue;
using std::unordered_set;
using std::vector;

int numSquares(int n)
{
    /******************** Solution 1 ********************/
    // int res = INT_MAX;
    // queue<int> pendingNums;
    // vector<int> combinations;
    // unordered_set<int> visitedCombinations;

    // for (int i = 1; i * i <= n; i++)
    // {
    //     combinations.push_back(i * i);
    // }

    // for (int i = 0; i < combinations.size(); i++)
    // {
    //     int layer = 1;
    //     pendingNums.push(combinations[i]);
    //     visitedCombinations.insert(combinations[i]);

    //     while (!pendingNums.empty())
    //     {
    //         int pendingSize = pendingNums.size();

    //         for (int nSub = pendingNums.size(); nSub > 0; nSub--)
    //         {
    //             int curNum = pendingNums.front();
    //             pendingNums.pop();

    //             if (curNum == n)
    //                 res = min(res, layer);

    //             for (int idx = 0; idx < combinations.size(); idx++)
    //             {
    //                 if (curNum + combinations[idx] <= n && visitedCombinations.find(curNum + combinations[idx]) == visitedCombinations.end())
    //                 {
    //                     pendingNums.push(curNum + combinations[idx]);
    //                     visitedCombinations.insert(curNum + combinations[idx]);
    //                 }
    //             }
    //         }

    //         layer++;
    //     }

    //     visitedCombinations.clear();
    // }

    // return res;
    /******************** Solution 1 ********************/

    /******************** Solution 2 ********************/

    // 參考 : https://www.youtube.com/watch?v=HLZLwjzIVGo

    /*
        這個陣列表示 :
            dp[總和] = 總和走的步數
    */
    // vector<int> dp(n + 1, n);
    // dp[0] = 0;

    // for (int target = 1; target < n + 1; target++)
    // {
    //     /*
    //         目標(target)是代表總和，從1開始最後到n
    //         最大不會超過n
    //     */
    //     for (int s = 1; s < target + 1; s++)
    //     {
    //         /*
    //             s代表小於目標的平方根
    //             最大不會超過target
    //         */
    //         int square = s * s;

    //         /*
    //             平方後超過總合就沒有必要計算
    //         */
    //         if (target - square < 0)
    //             break;

    //         /*
    //             target - square 表示與目標的差距
    //             dp[target - square] 表示這個差距要走的步數
    //             1 + dp[target - square] 的加一是加上走到這個差距的這一步
    //         */
    //         if (1 + dp[target - square] < dp[target])
    //             dp[target] = 1 + dp[target - square];
    //     }
    // }

    // return dp[n];
    /******************** Solution 2 ********************/

    /******************** Solution 3 ********************/
    // static vector<int> cntPerfectSquares = {{0}};

    // while (cntPerfectSquares.size() <= n)
    // {
    //     int m = cntPerfectSquares.size();
    //     int cntSquares = INT_MAX;

    //     for (int i = 1; i * i <= m; i++)
    //     {
    //         cntSquares = min(cntPerfectSquares[m - i * i] + 1, cntSquares);
    //     }

    //     cntPerfectSquares.push_back(cntSquares);
    // }

    // return cntPerfectSquares[n];
    /******************** Solution 3 ********************/

    /******************** Solution 4 ********************/

    vector<int> perfectSquares;
    vector<int> cntPerfectSquares(n);

    for (int i = 1; i * i <= n; i++)
    {
        perfectSquares.push_back(i * i);
        cntPerfectSquares[i * i - 1] = 1;
    }

    if (perfectSquares.back() == n)
        return 1;

    queue<int> searchQ;

    for (auto &i : perfectSquares)
    {
        searchQ.push(i);
    }

    int curCntPerfectSquares = 1;

    while (!searchQ.empty())
    {
        curCntPerfectSquares++;

        int searchQSize = searchQ.size();

        for (int i = 0; i < searchQSize; i++)
        {
            int tmp = searchQ.front();

            for (auto &j : perfectSquares)
            {
                if (tmp + j == n)
                {
                    return curCntPerfectSquares;
                }
                else if ((tmp + j < n) && (cntPerfectSquares[tmp + j - 1] == 0))
                {
                    cntPerfectSquares[tmp + j - 1] = curCntPerfectSquares;
                    searchQ.push(tmp + j);
                }
                else if (tmp + j > n)
                {
                    break;
                }
            }

            searchQ.pop();
        }
    }

    return 0;
    /******************** Solution 4 ********************/
}

int main()
{
    int n = 12;
    cout << numSquares(n) << endl; // 3

    n = 13;
    cout << numSquares(n) << endl; // 2

    n = 1;
    cout << numSquares(n) << endl; // 1
}