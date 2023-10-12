class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Approach 1: Sorting //
        // the majority element is more than [n / 2]
        // after sort, the middle of array is majority element and return it
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
        // End of Approach 1 //

        // Approach 2: Hash Map //
        // count the number of the elements in array
        // and than, search value of key that is more than [n / 2]
        class Solution
        {
        public:
            int majorityElement(vector<int> &nums)
            {
                int n = nums.size();
                unordered_map<int, int> m;

                for (int i = 0; i < n; i++)
                {
                    m[nums[i]]++;
                }
                n = n / 2;
                for (auto x : m)
                {
                    if (x.second > n)
                    {
                        return x.first;
                    }
                }
                return 0;
            }
        };
        // End of Approach 2 //

        // Approach 3: Moore Voting Algorithm //
        // count is number of the element in array
        // candidate is the potential majority element
        class Solution
        {
        public:
            int majorityElement(vector<int> &nums)
            {
                int count = 0;
                int candidate = 0;

                // The algorithm works on the basis of the assumption that
                // the majority element occurs more than n/2 times in the array
                for (int num : nums)
                {
                    if (count == 0)
                    {
                        candidate = num;
                    }

                    if (num == candidate)
                    {
                        count++;
                    }
                    else
                    {
                        count--;
                    }
                }

                return candidate;
            }
        };
        // End of Approach 3 //
    }
};