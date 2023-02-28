/*
* Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
* 
* Example 1:
*	Input: nums = [10,5,2,6], k = 100
*	Output: 8
*	Explanation: The 8 subarrays that have product less than 100 are:
*	[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
*	Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
* 
* Example 2:
*	Input: nums = [1,2,3], k = 0
*	Output: 0
* 
* Constraints:
*	1 <= nums.length <= 3 * 10^4
*	1 <= nums[i] <= 1000
*	0 <= k <= 10^6
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)  return 0;

        int left = 0, right = 0;
        int size = nums.size();
        int ans = 0, subarrayProduct = 1;

        while (right < size)
        {
            subarrayProduct *= nums[right];

            while (subarrayProduct >= k)
            {
                subarrayProduct /= nums[left];
                left++;
            }

            // 새로운 항목이 추가될 때마다 창의 길이만큼
            // 새 하위 배열을 추가한다.
            // {5, 2} 에 6이라는 값이 새로 추가된다면
            // {6}, {2,6}, {5,2,6} => 3만큼 추가된다.
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};

/*
* Result
* Time: 88 ms (72.28%), Space: 61.3 MB (75.62%)
*/