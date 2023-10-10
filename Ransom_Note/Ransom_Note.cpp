#include <string>
#include <array>

using std::array;
using std::string;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int i = 0;

        while (!magazine.empty())
        {
            if (i == ransomNote.length())
            {
                return true;
            }
            if (magazine.find(ransomNote[i]) != -1)
            {
                magazine.erase(magazine.find(ransomNote[i]), 1);
                i++;
            }
            else
            {
                return false;
            }
        }
        if (i == ransomNote.length())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};