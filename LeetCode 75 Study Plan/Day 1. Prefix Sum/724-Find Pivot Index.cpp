/*
* Given an array of integers nums, calculate the pivot index of this array.
* The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
* If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
* Return the leftmost pivot index. If no such index exists, return -1.
*
* Example 1:
*	Input: nums = [1,7,3,6,5,6]
*	Output: 3
*	Explanation:
*	The pivot index is 3.
*	Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
*	Right sum = nums[4] + nums[5] = 5 + 6 = 11
*
* Example 2:
* 	Input: nums = [1,2,3]
*	Output: -1
* 	Explanation:
* 	There is no index that satisfies the conditions in the problem statement.
*
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            rightSum += nums[i];
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != 0)
            {
                leftSum += nums[i - 1];
            }

            rightSum -= nums[i];

            if (leftSum == rightSum) return i;
        }

        return -1;
    }
};

/*
* Result
* Time: 19 ms (94.87%), Space: 31.1 MB (61.58%)
*/