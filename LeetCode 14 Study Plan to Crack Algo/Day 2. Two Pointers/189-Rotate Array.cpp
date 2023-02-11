/*
* Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
* Example 1:
*    Input: nums = [1,2,3,4,5,6,7], k = 3
*    Output: [5,6,7,1,2,3,4]
*    Explanation:
*    rotate 1 steps to the right: [7,1,2,3,4,5,6]
*    rotate 2 steps to the right: [6,7,1,2,3,4,5]
*    rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rotateNum = k % nums.size();
        if (rotateNum != 0) {
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + rotateNum);
            reverse(nums.begin() + rotateNum, nums.end());
        }
    }
};

/*
* Result
* Time: 35 ms (56.85%), Space: 24.9 MB (94.56%)
*/