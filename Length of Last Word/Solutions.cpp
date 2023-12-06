class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        int i = s.size() - 1;

        /*
            這邊先處理空白字元，接著計數字母數。
        */
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }

        while (i >= 0 and s[i] != ' ')
        {
            count++;
            i--;
        }

        return count;
    }
};