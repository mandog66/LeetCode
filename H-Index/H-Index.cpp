class Solution
{
public:
    // https://en.wikipedia.org/wiki/H-index
    int hIndex(vector<int> &citations)
    {

        int h = 0;
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());

        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] > i)
                h++;
        }
        cout << h << endl;
        return h;
    }
};