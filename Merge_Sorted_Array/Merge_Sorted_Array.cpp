class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (m > 0)
        {

            for (int i = 0; i < nums2.size(); i++)
            {

                nums1[i + m] = nums2[i];
            }
        }
        else
        {
            nums2.swap(nums1);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            int min = nums1[i];
            for (int j = i; j < nums1.size(); j++)
            {
                if (min > nums1[j])
                {
                    int tmp = min;
                    min = nums1[j];
                    nums1[i] = nums1[j];
                    nums1[j] = tmp;
                }
            }
        }
    }
};