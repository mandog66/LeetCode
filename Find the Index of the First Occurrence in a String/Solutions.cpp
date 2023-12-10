/*
    這題題目要看影片比較懂，用圖像的方式去理解程式。

    參考資料 : https://www.youtube.com/watch?v=JoF0Z7nVSrA
    參考資料 : http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
*/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle == "")
            return 0;
        /*
            lps 全名 Longest Prefix Suffix

            目的是為了找到 needle 的前綴和後綴兩個相同的"最大"長度。

            例子 :
                needle = "AAAA"
                lps = [0, 1, 2, 3]

                needle[0] 沒有前綴所以是 0 。
                needle[1] 在這個位置可以看成 needle = "AA"，這樣前綴就是 A 而後綴也是 A ，兩個相同，所以 lps = 1
                needle[2] 在這個位置可以看成 needle = "AAA"，這樣前綴就是 AA 而後綴也是 AA ，兩個相同，所以 lps = 2
                needle[3] 在這個位置可以看成 needle = "AAAA"，這樣前綴就是 AAA 而後綴也是 AAA ，兩個相同，所以 lps = 3

                * 在 needle[2] = "AAA"時，前綴完整是 ["A", "AA"] 兩個而後綴完整是 ["A", "AA"] 兩個，但我們要的是最大且相同的字串
                  所以前後綴符合祥同且最大是 "AA"，長度為 2 ，所以 lps = 2。
        */
        vector<int> lps(needle.size(), 0);
        int prevLPS = 0; // 前一個 LPS 的值
        int i = 1;       // 現在 LPS 的值。因為第一個字母的 LPS 的值一定是 0(沒有前綴)，所以我們從第二個字母開始計算 LPS。

        // 計算 needle 每個字母的 LPS 值
        while (i < needle.size())
        {
            if (needle[i] == needle[prevLPS])
            {
                lps[i] = prevLPS + 1;
                prevLPS++;
                i++;
            }

            else if (prevLPS == 0)
            {
                lps[i] = 0;
                i++;
            }

            else
            {
                prevLPS = lps[prevLPS - 1];
            }
        }

        int ptr_haystack = 0; // haystack 指標
        int ptr_needle = 0;   // needle 指標

        while (ptr_haystack < haystack.size())
        {
            // 兩個字母相同，指標都往前一個
            if (haystack[ptr_haystack] == needle[ptr_needle])
            {
                ptr_haystack++;
                ptr_needle++;
            }

            // 兩個字母不相同
            else
            {
                if (ptr_needle == 0)
                    ptr_haystack++;
                else
                    ptr_needle = lps[ptr_needle - 1];
            }

            if (ptr_needle == needle.size())
                return ptr_haystack - needle.size();
        }

        return -1;
    }
};