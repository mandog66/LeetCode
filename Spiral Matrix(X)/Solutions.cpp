class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();

        while (left < right && top < bottom)
        {
            for (int _left = left; _left < right; _left++)
            {
                res.push_back(matrix[top][_left]);
            }

            top += 1;

            for (int _top = top; _top < bottom; _top++)
            {
                res.push_back(matrix[_top][right - 1]);
            }

            right -= 1;

            if (top == bottom || left == right)
                break;

            for (int _right = right - 1; _right >= left; _right--)
            {
                res.push_back(matrix[bottom - 1][_right]);
            }

            bottom -= 1;

            for (int _bottom = bottom - 1; _bottom >= top; _bottom--)
            {
                res.push_back(matrix[_bottom][left]);
            }

            left += 1;
        }

        return res;
    }
};