/*
    可以觀看教學 : https://www.youtube.com/watch?v=FH9BxnzumVo
*/

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> res;
        const int rows = mat.size();
        const int cols = mat[0].size();

        bool going_up = true; // 判斷是往上還是往下
        int cur_rows = 0;
        int cur_cols = 0;

        while (res.size() != rows * cols)
        {
            if (going_up)
            {
                // 往上
                while (cur_rows >= 0 && cur_cols < cols)
                {
                    res.push_back(mat[cur_rows][cur_cols]);

                    cur_rows -= 1;
                    cur_cols += 1;
                }

                /*
                    會有兩種情況

                    1. col還在範圍內，row要往下一列
                    2. col不在範圍內，row要往下二列
                */
                if (cur_cols == cols)
                {
                    cur_cols -= 1;
                    cur_rows += 2;
                }
                else
                {
                    cur_rows += 1;
                }

                going_up = false;
            }
            else
            {
                // 往下
                while (cur_rows < rows && cur_cols >= 0)
                {
                    res.push_back(mat[cur_rows][cur_cols]);

                    cur_rows += 1;
                    cur_cols -= 1;
                }

                /*
                    會有兩種情況

                    1. row還在範圍內，col要往前一行
                    2. row不在範圍內，col要往前二行
                */
                if (cur_rows == rows)
                {
                    cur_rows -= 1;
                    cur_cols += 2;
                }
                else
                {
                    cur_cols += 1;
                }

                going_up = true;
            }
        }

        return res;
    }
};