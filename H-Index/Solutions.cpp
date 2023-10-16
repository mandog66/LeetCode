class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        // citations = {3, 0, 6, 1, 5}
        int n = citations.size(); // paper count
        int lo = 0;               // first paper
        int hi = n - 1;           // last paper
        int ans = 0;              // h-index

        sort(citations.begin(), citations.end()); // citations = {0, 1, 3, 5, 6}

        while (lo <= hi)
        {
            int m = (lo + hi) / 2;

            // (n - m) represent which paper
            if (citations[m] >= (n - m))
            {
                ans = n - m;
                hi = m - 1;
            }
            else
                // because citations[m] < n - m, can ignore forward m index
                lo = m + 1;
        }
        return ans;
    }
};