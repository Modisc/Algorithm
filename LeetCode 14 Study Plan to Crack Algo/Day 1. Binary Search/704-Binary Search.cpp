/*
* Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums.
* If target exists, then return its index. Otherwise, return -1.
* You must write an algorithm with O(log n) runtime complexity.
*
* Example 1:
*	Input: nums = [-1,0,3,5,9,12], target = 9
*	Output: 4
*	Explanation: 9 exists in nums and its index is 4
* Example 2:
*	Input: nums = [-1,0,3,5,9,12], target = 2
*	Output: -1
*	Explanation: 2 does not exist in nums so return -1
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = nums.size() / 2;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            if (nums[pivot] == target)     return pivot;
            else if (nums[pivot] < target)
            {
                left = pivot + 1;
                pivot = (right + left) / 2;
            }
            else
            {
                right = pivot - 1;
                pivot = (right + left) / 2;
            }
        }

        return -1;
    }
};

/*
* Result
* Time: 43 ms (54.5%), Space: 27.7 MB (17.45%)
*/