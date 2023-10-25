/*
    I didn't get it.(See Solutions.cpp)

    Hang in there!

    I have faith in you!
*/

#include <iostream>
#include <vector>

using namespace std;

/*
    Approach 1 The Nuts and Bolts of the Two-Pass Method
*/
int candy(vector<int> &ratings)
{
    const int n = ratings.size(); // ratings length
    vector<int> candies(n, 1);    // every child can get the candies and get at least one candy

    for (int i = 1; i < n; i++)
    {
        /*
            compare left ratings from ratings[1]
        */
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        /*
            compare right ratings from ratings[n - 2]
            if i ratings more than neighbors, i can get more candies
        */
        if (ratings[i] > ratings[i + 1])
            candies[i] = max(candies[i], candies[i + 1] + 1);
    }

    int totalCandies = 0;
    for (int c : candies)
        /*
            sum the candies
        */
        totalCandies += c;

    return totalCandies;
}

/*
    Approach 2 One-Pass Greedy Algorithm: Up-Down-Peak Method
*/
int candy_(vector<int> &ratings)
{
    const int n = ratings.size();
    int up = 0;   // 計算以遞增排序的 ratings 數量
    int down = 0; // 計算以遞減排序的 ratings 數量
    int peak = 0; // 紀錄在遞增排序中在最後一個(下一個 ratings 變小)前的 ratings 數量
    int ret = 1;  // return value

    vector<int> f, b;

    for (int i = 0; i < n - 1; i++)
        f.push_back(ratings[i]);

    for (int i = 1; i < n; i++)
        b.push_back(ratings[i]);

    for (int i = 0; i < n - 1; i++)
    {
        if (f[i] < b[i])
        {
            /*
                遞增方式排列
            */
            peak = up + 1;
            up++;
            down = 0;
            ret += (1 + up);
        }
        else if (f[i] == b[i])
        {
            /*
                前後分數相同，不是遞增也不是遞減
            */
            up = 0;
            down = 0;
            peak = 0;
            ret += 1;
        }
        else
        {
            /*
                遞減方式排列
            */
            down += 1;
            up = 0;

            /*
                下面的判斷是比較 peak 的數量(遞增最後一個前的數量)有沒有超過 down 也就是遞減的數量
                如果 peak >= down，就 1 + down - 1，其實就是 + down，否則 1 + down

                首先，為什麼先 + 1，這代表是分數大的小孩分到的糖果要多一顆
                假設 ratings = {3, 2, 1}，ret = 1
                3 > 2，所以 3 要多拿一顆，2 > 1，所以 2 要多拿一顆
                總共是 1 + 2 + 3 顆(按照原本的題意是 3 + 2 + 1 的方式總和)

                接著，為什麼要 -1 ，這代表遞減數量還沒超過遞增的數量，所以把 +1 去掉
                也可以說當遞減數量超過遞增數量時，要把糖果多給在 peak 的小孩
                假設 ratings = {1, 2, 5, 3, 1}
                程式最後是 1 + 2 + 3 + 1 + 2 顆(按照原本的題意是 1 + 2 + 3 + 2 + 1 的方式總和)
                3 和 1 都還在 peak 範圍內，所以只 + down
                再假設 ratings = {1, 2, 5, 3, 1, 0}
                程式最後是 1 + 2 + 3 + 1 + 2 + 4 顆(按照原本的題意是 1 + 2 + 4 + 3 + 2 + 1 的方式總和)
                0 已經超過 peak 範圍，所以要把糖果加回到 peak，也就是 1 + down

                為什麼是要比較 peak 呢
                可以看上面的假設，當 ratings = {1, 2, 5, 3, 1, 0}，程式最後是 1 + 2 + 3 + 1 + 2 + 4 顆
                5 是 peak 的地方，前面有兩個小孩，所以 peak = 2
                1 是 down 在 peak = 2 時的臨界點，可以看到如果 down 再 +1 就是 3 會等於 peak
                但 peak 是高點，要比相鄰的小孩有更多的糖果，所以當 down 超過 peak 就要多加 1 ，把糖果多給 peak
            */
            if (peak >= down)
                ret += (1 + down - 1);
            else
                ret += (1 + down);
        }
    }
    return ret;
}

/*  類似方法2 但更簡潔一點
public int Candy(int[] ratings) {
    if (ratings.Length == 0) return 0;
    int ret = 1;
    int up = 0, down = 0, peak = 0;
    for (int i = 1; i < ratings.Length; i++) {
        if (ratings[i - 1] < ratings[i]) {
            peak = ++up;
            down = 0;
            ret += 1 + up;
        } else if (ratings[i - 1] == ratings[i])  {
            peak = up = down = 0;
            ret += 1;
        } else {
            up = 0;
            down++;
            ret += 1 + down + (peak >= down ? -1 : 0);
        }
    }
    return ret;
}
*/

int main()
{
    // vector<int> ratings = {1, 0, 2}; // return 5 // 2+1+2
    // vector<int> ratings = {1, 3, 2, 2, 1}; // return 7 // 1+2+1+2+1
    // vector<int> ratings = {1, 2, 87, 87, 87, 2, 1}; // return 13    // 1+2+3+1+3+2+1
    // vector<int> ratings = {29, 51, 87, 87, 72, 12}; // return 12    // 1+2+3+3+2+1
    // vector<int> ratings = {1, 3, 4, 5, 2}; // return 11  // 1+2+3+4+1
    vector<int> ratings = {1, 6, 10, 8, 7, 3, 2}; // return 18    // 1+2+5+4+3+2+1
    // vector<int> ratings = {3, 2, 1, 1, 4, 3, 3}; // return 11    // 3+2+1+1+2+1+1
    // vector<int> ratings = {0};
    cout << "Approach 1 " << candy(ratings) << endl;
    cout << "Approach 2 " << candy_(ratings) << endl;
}
