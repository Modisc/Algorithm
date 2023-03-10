/*
* You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
* All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
* Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
* Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
* 
* Example 1:
*	Input: nums = [2,3,2]
*	Output: 3
*	Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
* 
* Example 2:
*	Input: nums = [1,2,3,1]
*	Output: 4
*	Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
*	Total amount you can rob = 1 + 3 = 4.
* 
* Example 3:
*	Input: nums = [1,2,3]
*	Output: 3
* 
* Constraints:
*	1 <= nums.length <= 100
*	0 <= nums[i] <= 1000
*/

class Solution {
public:
    int dp(vector<int>& nums, int begin, int end)
    {
        int first = 0;
        int second = 0;

        for (int i = begin; i <= end; i++)
        {
            int tmp = first;
            int current = nums[i];
            first = max(first, current + second);
            second = tmp;
        }

        return first;
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)   return 0;
        if (size == 1)   return nums[0];

        int max1 = dp(nums, 0, size - 2);
        int max2 = dp(nums, 1, size - 1);

        return max(max1, max2);
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 7.9 MB (67.27%)
*/