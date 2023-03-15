/*
* Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
* 
* Example 1:
*	Input: nums = [1,5,11,5]
*	Output: true
*	Explanation: The array can be partitioned as [1, 5, 5] and [11].
* 
* Example 2:
*	Input: nums = [1,2,3,5]
*	Output: false
*	Explanation: The array cannot be partitioned into equal sum subsets.
* 
* Constraints:
*	1 <= nums.length <= 200
*	1 <= nums[i] <= 100
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto x : nums)
            sum += x;

        if (sum % 2 != 0)    return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (auto x : nums)
            for (int i = sum; i >= x; i--)
                dp[i] = dp[i] || dp[i - x];

        return dp[sum];
    }
};

/*
* Result
* Time: 153 ms (87.14%), Space: 9.5 MB (98.57%)
*/