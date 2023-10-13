/*

    Time Complexity : O(N^2), Where N is the size of the Array(prices). As we check for possible pair, and the
    total number of pairs are : N*(N–1)/2.

    Space complexity : O(1), Constant space.

    Using Array(Two Nested Loop). Brute Force Approach.

    Note : This will give TLE.

*/

/***************************************** Approach 1 Code *****************************************/
/*
    vector<int> prices = {7, 1, 5, 3, 6, 4};
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // Brute Force Approach.
        int n = prices.size(), maxProfit = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] - prices[i] > maxProfit)
                {
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        return maxProfit;
    }
};

/*

    Time Complexity : O(N), As we iterate the array(prices) two times. Where N = size of the array.

    Space complexity : O(N), Array(maxPrices) space.

    Solved using Dynamic Programming Approach(tabulation).

*/

/***************************************** Approach 2 Code *****************************************/
/*
    vector<int> prices = {7, 1, 5, 3, 6, 4};
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> maxPrices(n, 0);
        maxPrices[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            /*
                i is the price you can get if you sell it today
            */
            maxPrices[i] = max(maxPrices[i + 1], prices[i]);
        }
        /*
            maxPrices = {7, 6, 6, 6, 6, 4}
        */
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, maxPrices[i] - prices[i]);
        }
        return maxProfit;
    }
};

/*

    Time Complexity : O(N), As we iterate the array(prices) two times. Where N = size of the array.

    Space Complexity : O(1), Constant space.

    Solved using Dynamic Programming Approach(Space optimisation).

*/

/***************************************** Approach 3 Code *****************************************/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int buyAtPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            buyAtPrice = min(buyAtPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - buyAtPrice);
        }
        return maxProfit;
    }
};