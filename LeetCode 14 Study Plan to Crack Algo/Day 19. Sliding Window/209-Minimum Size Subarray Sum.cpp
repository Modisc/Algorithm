/*
* Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
* whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
* 
* Example 1:
*	Input: target = 7, nums = [2,3,1,2,4,3]
*	Output: 2
*	Explanation: The subarray [4,3] has the minimal length under the problem constraint.
* 
* Example 2:
*	Input: target = 4, nums = [1,4,4]
*	Output: 1
* 
* Example 3:
*	Input: target = 11, nums = [1,1,1,1,1,1,1,1]
*	Output: 0
* 
* Constraints:
*	1 <= target <= 10^9
*	1 <= nums.length <= 10^5
*	1 <= nums[i] <= 10^4
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int size = nums.size();
        int sum = 0;
        int ans = INT_MAX;

        while (right < size)
        {
            sum += nums[right];
            while (sum >= target)
            {
                ans = min(ans, right - left + 1);
                if (ans == 1)    return ans;
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};

/*
* Result
* Time: 39 ms (75.95%), Space: 28.2 MB (59.64%)
*/