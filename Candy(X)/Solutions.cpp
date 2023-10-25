class Solution
{
public:
    int candy(std::vector<int> &ratings)
    {
        int n = ratings.size();
        std::vector<int> candies(n, 1);

        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for (int candy : candies)
        {
            totalCandies += candy;
        }

        return totalCandies;
    }
};

/*
class Solution:
    def candy(self, ratings: List[int]) -> int:
        if not ratings:
            return 0

        ret, up, down, peak = 1, 0, 0, 0

        for prev, curr in zip(ratings[:-1], ratings[1:]):
            if prev < curr:
                up, down, peak = up + 1, 0, up + 1
                ret += 1 + up
            elif prev == curr:
                up = down = peak = 0
                ret += 1
            else:
                up, down = 0, down + 1
                ret += 1 + down - int(peak >= down)

        return ret
*/

/*
public int Candy(int[] ratings)
{
    if (ratings.Length == 0)
        return 0;
    int ret = 1;
    int up = 0, down = 0, peak = 0;
    for (int i = 1; i < ratings.Length; i++)
    {
        if (ratings[i - 1] < ratings[i])
        {
            peak = ++up;
            down = 0;
            ret += 1 + up;
        }
        else if (ratings[i - 1] == ratings[i])
        {
            peak = up = down = 0;
            ret += 1;
        }
        else
        {
            up = 0;
            down++;
            ret += 1 + down + (peak >= down ? -1 : 0);
        }
    }
    return ret;
}
*/