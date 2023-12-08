class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;

        vector<string> v(numRows, "");
        int j = 0;    // 字母放在 v 的指標
        int dir = -1; // 字母加入 v 的方向
        for (int i = 0; i < s.size(); i++)
        {
            // 更改加入方向
            if (j == numRows - 1 || j == 0)
                dir *= (-1);

            v[j] += s[i];

            if (dir == 1)
                j++;
            else
                j--;
        }

        string res;
        /*
            auto it : 複製元素
            auto &it : 可以更改元素

            參考資料 : https://learn.microsoft.com/zh-tw/cpp/cpp/auto-cpp?view=msvc-170
        */
        for (auto &it : v)
            res += it;

        return res;
    }
};