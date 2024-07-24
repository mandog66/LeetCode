#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::multiset;
using std::vector;

vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<vector<int>> res;
    /*
        建築高度的排序集合，能夠重複和高度從0開始

        最大高度會排在最後一個

        假設現在是進入點(高度為負值)，那會將該點高度加入

        假設是離開點(高度為正值)，代表該點的建築已經走完兩點了，所以將該點高度刪除

        而且是排序狀態，所以如果該點是最大高度，該點刪除後就會有第二大高度，這就會是離開點的高度
    */
    multiset<int> pq = {0};

    // 建築的進入座標(左上角)和離開座標(右上角)
    vector<std::pair<int, int>> points;
    for (auto b : buildings)
    {
        // 利用高度的正負值判斷是進入點(負)還是離開點(正)
        points.push_back(std::make_pair(b[0], -b[2]));
        points.push_back(std::make_pair(b[1], b[2]));
    }

    // 依照x座標從小到大遍歷
    std::sort(points.begin(), points.end());

    // 前一個點的高度(從0開始)
    int ongoingHeight = 0;

    for (int i = 0; i < points.size(); i++)
    {
        int x = points[i].first;  // x座標
        int y = points[i].second; // 建築高度

        // 判斷是進入點/離開點
        if (y < 0)
            pq.insert(-y);
        else
            pq.erase(pq.find(y));

        // 目前所有建築的最大高度
        auto pqTop = *pq.rbegin();

        if (ongoingHeight != pqTop)
        {
            // 可能是進入點高度更高或是到達離開點
            ongoingHeight = pqTop;
            res.push_back({x, ongoingHeight});
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> res = getSkyline(buildings);

    std::cout << "[";
    for (int row = 0; row < res.size(); row++)
    {
        std::cout << (row == 0 ? "[" : ", [");
        for (int col = 0; col < res[0].size(); col++)
        {
            std::cout << (col == 0 ? "" : ", ") << res[row][col];
        }
        std::cout << "]";
    }
    std::cout << "]" << std::endl; // [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
}