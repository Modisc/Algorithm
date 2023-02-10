/*
* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
* You must write an algorithm with O(log n) runtime complexity.
* 
* Example 1:
*	Input: nums = [1,3,5,6], target = 5
*	Output: 2
*
* Example 2:
*	Input: nums = [1,3,5,6], target = 2
*	Output: 1
*
* Example 3:
*	Input: nums = [1,3,5,6], target = 7
*	Output: 4
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int pivot = -1;
        while (left <= right)
        {
            pivot = left + (right - left) / 2;
            if (nums[pivot] == target)   return pivot;
            else if (nums[pivot] < target)
            {
                left = pivot + 1;
            }
            else
            {
                right = pivot - 1;
            }
        }
        return left;
    }
};

/*
* Result
* Time: 5 ms (66.2%), Space: 9.7 MB (30.43%)
*/