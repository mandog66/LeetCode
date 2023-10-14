class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        /*
            nums = {2, 3, 1, 1, 4};
        */
        int n = nums.size();
        int maxReach = 0; // 最遠可以抵達到的位置
        for (int i = 0; i < n; i++)
        {
            // index 是現在需要到達的位置
            // 也可以看成nums[i] 前面有多少個元素
            if (i > maxReach)
                return false;
            // 更新 maxReach
            // i + nums[i] => 已經經過的元素個數 + 可以往前的最大距離(包含現在的元素)
            // nums[3] == 1
            // 3 的意思是前面已經經過的元素個數，也代表目前已經可以到達這裡
            // 1 的意思是到這裡包含前面的元素最遠可以抵達的位置
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};