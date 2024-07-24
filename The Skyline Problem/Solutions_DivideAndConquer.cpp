#include <iostream>
#include <vector>

using std::vector;

// reference : https://www.youtube.com/watch?v=Cv0ft2dFz80&t=61s

vector<vector<int>> merge_skylines(vector<vector<int>> left_skylines, vector<vector<int>> right_skylines)
{
    vector<vector<int>> skykline;

    int l = 0, r = 0;   // 左指標/右指標
    int lh = 0, rh = 0; // 左-最後遇到的高/右-最後遇到的高
    int x = 0, y = 0;   // 合法的座標

    while (l < left_skylines.size() && r < right_skylines.size())
    {
        // 選擇比較小的x座標的建築
        if (left_skylines[l][0] < right_skylines[r][0])
        {
            // 左邊的建築比較小
            x = left_skylines[l][0];
            y = left_skylines[l][1];
            lh = y;

            if (y < rh)
                y = rh;

            l += 1;
        }
        else if (left_skylines[l][0] > right_skylines[r][0])
        {
            // 右邊的建築比較小
            x = right_skylines[r][0];
            y = right_skylines[r][1];
            rh = y;

            if (y < lh)
                y = lh;

            r += 1;
        }
        else
        {
            // 左右的x座標相同
            x = left_skylines[l][0];
            y = std::max(left_skylines[l][1], right_skylines[r][1]);

            lh = left_skylines[l][1];
            rh = right_skylines[r][1];

            l += 1;
            r += 1;
        }

        skykline.push_back({x, y});
    }

    // 加入剩下的左座標
    while (l < left_skylines.size())
        skykline.push_back(left_skylines[l++]);

    // 加入剩下的右座標
    while (r < right_skylines.size())
        skykline.push_back(right_skylines[r++]);

    // 移除不合法的座標
    vector<vector<int>> res = {skykline[0]};
    for (int i = 1, j = 0; i < skykline.size(); i++)
    {
        if (skykline[i][1] == res[j][1])
            continue;

        res.push_back(skykline[i]);
        j += 1;
    }

    return res;
}

vector<vector<int>> divide_and_conquer(vector<vector<int>> &buildings, int l, int r)
{
    if (l == r)
    {
        // 拆分成單個建築並把建築的左上座標和右下座標記錄下來
        int left = buildings[l][0];
        int right = buildings[l][1];
        int hight = buildings[l][2];

        return {{left, hight}, {right, 0}};
    }

    int m = l + (r - l) / 2;
    vector<vector<int>> left_skylines = divide_and_conquer(buildings, l, m);
    vector<vector<int>> right_skylines = divide_and_conquer(buildings, m + 1, r);

    return merge_skylines(left_skylines, right_skylines);
}

vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    return divide_and_conquer(buildings, 0, buildings.size() - 1);
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