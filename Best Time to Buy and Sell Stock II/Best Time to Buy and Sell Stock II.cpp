class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buyAtPrice = INT_MAX;
        int single_profit = 0;
        int more_profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < buyAtPrice)
            {
                buyAtPrice = prices[i];
            }

            if (prices[i] - buyAtPrice > single_profit)
            {
                single_profit = prices[i] - buyAtPrice;
            }
        }

        if (single_profit == 0)
        {
            cout << single_profit << endl;
            return 0;
        }

        buyAtPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {

            buyAtPrice = min(prices[i], buyAtPrice);
            if (prices[i] > buyAtPrice)
            {
                more_profit += prices[i] - buyAtPrice;
                buyAtPrice = prices[i];
            }
        }
        return max(single_profit, more_profit);
    }
};