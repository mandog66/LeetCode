/*
    參考資料 : https://www.youtube.com/watch?v=TzMl4Z7pVh8
*/

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        vector<string> line;
        int length = 0;
        int i = 0;

        while (i < words.size())
        {
            if (length + line.size() + words[i].size() > maxWidth)
            {
                int extra_space = maxWidth - length;
                int spaces = extra_space / max(1, int(line.size() - 1));
                int remainder = extra_space % max(1, int(line.size() - 1));

                for (int j = 0; j < max(1, int(line.size() - 1)); j++)
                {
                    for (int s = 0; s < spaces; s++)
                    {
                        line[j] += " ";

                        if (remainder)
                        {
                            line[j] += " ";
                            remainder--;
                        }
                    }
                }

                for (int s = 1; s < line.size(); s++)
                    line[0] += line[s];
                res.push_back(line[0]);
                line.clear();
                length = 0;
            }

            line.push_back(words[i]);
            length += words[i].size();
            i++;
        }

        string last_line = "";
        for (int ll = 0; ll < line.size(); ll++)
        {
            if (ll != line.size() - 1)
            {
                last_line += line[ll];
                last_line += " ";
            }
            else
            {
                last_line += line[ll];
            }
        }

        int trail_space = maxWidth - last_line.size();
        for (int ts = 0; ts < trail_space; ts++)
            last_line += " ";
        res.push_back(last_line);

        return res;
    }
};