#include <iostream>
#include <unordered_set>

using std::unordered_set;

int backTrack(int row, int n, int res, unordered_set<int> col, unordered_set<int> posDiag, unordered_set<int> negDiag)
{
    if (row == n)
        return res + 1;

    for (int i = 0; i < n; i++)
    {
        if (col.find(i) != col.end() || posDiag.find(row + i) != posDiag.end() || negDiag.find(row - i) != negDiag.end())
            continue;

        /*
            這裡用了一個小訣竅 :
                在同一個 col 不用說，queen 是不能放的，所以直接把目前的 col 加到 set。

                對角線來說有正斜率()和負斜率()，分別處理 : (假設 N = 4)
                    正斜率 : 假設當前 queenIdx = (0, 1)，那正斜率的攻擊範圍在 row = 1 時落在 (1, 0)，發現當前 row + col 會等於正斜率的攻擊範圍也是 row + col 。
                    負斜率 : 假設當前 queenIdx = (0, 1)，那負斜率的攻擊範圍在 row = 1 時落在 (1, 2)，發現當前 row - col 會等於負斜率的攻擊範圍也是 row - col 。
        */
        col.insert(i);
        posDiag.insert(row + i);
        negDiag.insert(row - i);
        res = backTrack(row + 1, n, res, col, posDiag, negDiag);
        col.erase(i);
        posDiag.erase(row + i);
        negDiag.erase(row - i);
    }

    return res;
}

int totalNQueens(int n)
{
    unordered_set<int> col, posDiag, negDiag;
    return backTrack(0, n, 0, col, posDiag, negDiag);
}

int main(int argc, char *argv[])
{
    int n = 1;
    std::cout << totalNQueens(n) << std::endl; // 1

    n = 2;
    std::cout << totalNQueens(n) << std::endl; // 0

    n = 3;
    std::cout << totalNQueens(n) << std::endl; // 0

    n = 4;
    std::cout << totalNQueens(n) << std::endl; // 2

    n = 5;
    std::cout << totalNQueens(n) << std::endl; // 10

    n = 6;
    std::cout << totalNQueens(n) << std::endl; // 4

    n = 7;
    std::cout << totalNQueens(n) << std::endl; // 40

    n = 8;
    std::cout << totalNQueens(n) << std::endl; // 92

    n = 9;
    std::cout << totalNQueens(n) << std::endl; // 352
}