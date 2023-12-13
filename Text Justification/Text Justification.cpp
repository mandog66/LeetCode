#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int wordsSize = words.size();
    string word = "";   // 暫存字串
    int wordCount = 0;  // 計算這行有多少個單字
    vector<string> res; // 結果

    for (int i = 0; i < wordsSize; i++)
    {
        // 判斷這行字串有超過 maxWidth
        // 為字串加上空白
        if (words[i].size() + word.size() > maxWidth)
        {
            int wordSize = word.size() - wordCount; // 不包含空白的字串長度
            int wordSpace = maxWidth - wordSize;    // 有多少空白需要加入
            int slot = wordCount - 1;               // 單字與單字之間的空格數量

            // 空白數量剛好能夠平分到 slot 中
            if (slot != 0 && wordSpace % slot == 0)
            {
                string space = ""; // slot 的空白
                word = "";         // 更新字串符合題意

                for (int j = 0; j < (wordSpace / slot); j++)
                {
                    space += " ";
                }

                for (int j = (i - wordCount); j < i; j++)
                {
                    // 最後一個單字不用空白
                    if (j == (i - 1))
                    {
                        word += words[j];
                    }
                    else
                    {
                        word += words[j];
                        word += space;
                    }
                }
            }
            // 空白數量不能平分到 slot 中
            else if (slot != 0 && wordSpace % slot != 0)
            {
                int wordSpaceCount = wordSpace % slot;     // 多餘的空白數量
                int lastWordSpaceCount = wordSpace / slot; // 單字與單字間能夠平分的空白數量
                string space = "";
                word = "";

                for (int j = i - wordCount; j < i; j++)
                {
                    word += words[j];

                    // 多餘的空白由左至右加到格子中
                    if (wordSpaceCount != 0)
                    {
                        word += " ";
                        for (int m = 0; m < lastWordSpaceCount; m++)
                        {
                            word += " ";
                        }
                        wordSpaceCount--;
                    }
                    // 加入能夠平分的空白
                    else
                    {
                        if (j != (i - 1))
                        {
                            for (int m = 0; m < lastWordSpaceCount; m++)
                            {
                                word += " ";
                            }
                        }
                    }
                }
            }
            // slot == 0
            else
            {
                word.pop_back();
                while (word.size() < maxWidth)
                {
                    word += " ";
                }
            }

            // 處理完的 word 加到 res
            // 初始化變數
            res.push_back(word);
            word = "";
            wordCount = 0;
            i--;
        }
        // 判斷這行字串沒有超過 maxWidth
        // 將單字加到 word 中
        else
        {
            // 判斷迴圈到最後一個單字
            // 為最後的單字加上空白，滿足 maxWidth 的條件
            // 最後把字串加到 res 中
            if (i == wordsSize - 1)
            {
                word += words[i];
                while (word.size() < maxWidth)
                {
                    word += " ";
                }
                res.push_back(word);
            }
            // 判斷迴圈不是最後一個單字
            // 將單字加到 word 中
            else
            {
                word += (words[i] + " ");
                wordCount++;
            }
        }
    }

    return res;
}

void show_vector(vector<string> words)
{
    const int n = words.size();
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << "\"";
            cout << words[i];
            cout << "\"\n"
                 << endl;
        }
        else
        {
            cout << "\"";
            cout << words[i];
            cout << "\",\n";
        }
    }
}

int main()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    show_vector(fullJustify(words, maxWidth));

    words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    maxWidth = 16;
    show_vector(fullJustify(words, maxWidth));

    words = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a",
             "computer.", "Art", "is", "everything", "else", "we", "do"};
    maxWidth = 20;
    show_vector(fullJustify(words, maxWidth));
}
