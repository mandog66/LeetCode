/*

    Time Complexity : O(N^2), Where N is the size of the Array(nums). Here Two nested loop creates the time
    complexity.

    Space complexity : O(1), Constant space. Extra space is only allocated for the Array(output), however the
    output does not count towards the space complexity.

    Solved using Array(Two Nested Loop). Brute Force Approach.

    Note : This will give TLE.

*/

/***************************************** Approach 1 *****************************************/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output;
        for (int i = 0; i < n; i++)
        {
            int product = 1;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                product *= nums[j];
            }
            output.push_back(product);
        }
        return output;
    }
};

/*

    Time Complexity : O(N), As we iterate the Array(nums) thrice. Where N = size of the array.

    Space complexity : O(N), Array(left_Product and right_Product) space.

    Solved using Dynamic Programming Approach(tabulation).

*/

/***************************************** Approach 2 *****************************************/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_Product(n);  // 將 index 左邊的數字計算完成
        vector<int> right_Product(n); // 將 index 右邊的數字計算完成
        left_Product[0] = 1;          // index 從 1 開始，要把 index = 0 的數字保留起來加上計算是乘法，所以設成 1
        for (int i = 1; i < n; i++)
        {
            // 完成 i 左邊的計算
            // i = 0, 每有左邊的數字所以忽略
            // i = 1, 左邊有 i = [0] 這個數字，所以是 [i - 1]
            // i = 2, 左邊有 i = [0, 1] 兩個數字，但前面已經計算過 i = [0]了，所以只要在計算 [i - 1] 就好
            // 以此類推
            left_Product[i] = left_Product[i - 1] * nums[i - 1];
        }
        right_Product[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            // 和左邊算法相同，只是換成右邊
            // 而 i = n - 1 沒有右邊的數字所以跳過
            right_Product[i] = right_Product[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            // 最後把左右兩邊的數字乘起來就是答案
            ans[i] = left_Product[i] * right_Product[i];
        }
        return ans;
    }
};

/*

    Time Complexity : O(N), As we iterate the Array(nums) twice. Where N = size of the array.

    Space complexity : O(1), Constant space. Extra space is only allocated for the Array(output), however the
    output does not count towards the space complexity.

    Solved using Dynamic Programming Approach(Space Optimization). Optimized Approach.

*/

/***************************************** Approach 3 *****************************************/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output(n); // 可以想像成左邊的乘積
        output[0] = 1;         // 要保留 index = 0 的數字，所以把答案 index = 0 填上 1
        for (int i = 1; i < n; i++)
        {
            // 可以看成是第二個方法中計算左邊的步驟
            output[i] = output[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            // 這裡就和第二個方法不同，但概念類似
            // 右邊的計算變成一個整數變數(方法二是陣列)
            // i = n - 1 已經在上面的計算完成(因為沒有右邊的數字)
            // 把右邊的乘積和 output[i] 相乘得到結果
            // 將 i = n - 1 的數字計算到 right 中，目的是要讓後面的數字得到右邊的乘積
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};