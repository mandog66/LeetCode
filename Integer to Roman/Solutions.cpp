class Solution
{
public:
    string intToRoman(int num)
    {
        int nums[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int n = 12;
        string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string res = "";

        while (num > 0)
        {
            int div = num / nums[n]; // 算出要印出多少次
            num = num % nums[n];     // 算出剩餘的數字
            while (div--)
            {
                res += sym[n];
            }
            n--;
        }

        return res;
    }
};