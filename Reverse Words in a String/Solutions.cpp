class Solution
{
public:
    string reverseWords(string s)
    {
        if (s.size() == 0)
            return "";

        stack<string> stack;
        string res = "";

        // 擷取單字並忽略前後的空白
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;

            string word;

            while (i < s.size() && s[i] != ' ')
            {
                word += s[i++];
            }

            stack.push(word);
        }

        // 從 stack 的 top 取出單字
        // 單字和單字之間加入空白
        while (!stack.empty())
        {
            res += stack.top();
            stack.pop();
            if (!stack.empty())
                res += " ";
        }

        return res;
    }
};