#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int openLock(vector<string> &deadends, string target)
{
    // 轉動輪子到下一個
    unordered_map<char, char> nextSlot = {
        {'0', '1'},
        {'1', '2'},
        {'2', '3'},
        {'3', '4'},
        {'4', '5'},
        {'5', '6'},
        {'6', '7'},
        {'7', '8'},
        {'8', '9'},
        {'9', '0'}};

    // 轉動輪子到上一個
    unordered_map<char, char> prevSlot = {
        {'0', '9'},
        {'1', '0'},
        {'2', '1'},
        {'3', '2'},
        {'4', '3'},
        {'5', '4'},
        {'6', '5'},
        {'7', '6'},
        {'8', '7'},
        {'9', '8'}};

    // 紀錄已經被拜訪過的組合(包括"deadends")
    unordered_set<string> visitedCombinations = {deadends.begin(), deadends.end()};

    // 稍後要處理的組合
    queue<string> pendingCombinations;
    int res = 0;

    // 如果"0000"在被拜訪紀錄裡
    if (visitedCombinations.find("0000") != visitedCombinations.end())
        return -1;

    // 初始化
    pendingCombinations.push("0000");
    visitedCombinations.insert("0000");

    while (!pendingCombinations.empty())
    {
        for (int currLevelNodesCount = pendingCombinations.size(); currLevelNodesCount > 0; currLevelNodesCount--)
        {
            string currentCombination = pendingCombinations.front();
            pendingCombinations.pop();

            if (currentCombination == target)
                return res;

            for (int wheel = 0; wheel < 4; wheel++)
            {
                string newCombination = currentCombination;
                newCombination[wheel] = nextSlot[newCombination[wheel]];

                if (visitedCombinations.find(newCombination) == visitedCombinations.end())
                {
                    pendingCombinations.push(newCombination);
                    visitedCombinations.insert(newCombination);
                }

                newCombination = currentCombination;
                newCombination[wheel] = prevSlot[newCombination[wheel]];

                if (visitedCombinations.find(newCombination) == visitedCombinations.end())
                {
                    pendingCombinations.push(newCombination);
                    visitedCombinations.insert(newCombination);
                }
            }
        }

        res++;
    }

    return -1;
}

int main()
{
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    cout << openLock(deadends, target) << endl; // 6

    deadends = {"8888"};
    target = "0009";
    cout << openLock(deadends, target) << endl; // 1

    deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    target = "8888";
    cout << openLock(deadends, target) << endl; // -1
}
