class Solution
{
public:
    int romanToInt(string s)
    {
        /*
            s = "III";
        */

        unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.size();
        int res = roman[s[n - 1]];

        /*
            如果沒有 n - 1 而是單單只用 n 的話，判斷到最後一個字元時，i + 1 會超出字串長度。
            這樣做會導致最後一個字元不會被處理，所以我直接將它加到 res 中。
        */
        for (int i = 0; i < n - 1; i++)
        {
            if (roman[s[i]] >= roman[s[i + 1]])
            {
                res += roman[s[i]];
            }
            else
            {
                res -= roman[s[i]];
            }
        }

        return res;
    }
};