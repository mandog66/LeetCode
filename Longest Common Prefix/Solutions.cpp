class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        string res = "";

        /*
            ** 假設只有小寫字母 **
            按照字母順序排序可以將"最不同"的單字放到最後面。
            Ex.
                before sort {"flower", "flow", "flight"}
                after sort  {"flight", "flow", "flower"}

                before sort {"apple", "appetizer", "applied", "application", "app"}
                after sort  {"app", "appetizer", "apple", "application", "applied"}

                before sort {"preheat", "oven", "prehistoric"}
                after sort  {"oven", "preheat", "prehistoric"}
        */
        sort(strs.begin(), strs.end());

        for (int i = 0; i < min(strs[0].size(), strs[n - 1].size()); i++)
        {
            if (strs[0][i] != strs[n - 1][i])
                return res;
            else
                res += strs[0][i];
        }

        return res;
    }
};