class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = 0, r = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < prices[min])
            {

                min = i;
            }
            else
            {
                if (prices[i] - prices[min] > r)
                {

                    r = prices[i] - prices[min];
                }
            }
        }
        return r;
    }
};