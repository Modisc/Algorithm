/*
* Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
* 
* Example 1:
*	Input: nums = [1,2,3]
*	Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
* 
* Example 2:
*	Input: nums = [0,1]
*	Output: [[0,1],[1,0]]
* 
* Example 3:
*	Input: nums = [1]
*	Output: [[1]]
* 
* Constraints:
*	1 <= nums.length <= 6
*	-10 <= nums[i] <= 10
*	All the integers of nums are unique.
*/

class Solution {
public:
    void mix(vector<int>& nums, int first, int last, vector<vector<int>>& result)
    {
        if (first == last)
        {
            result.push_back(nums);
            return;
        }

        for (int i = first; i <= last; i++)
        {
            swap(nums[i], nums[first]);
            mix(nums, first + 1, last, result);
            swap(nums[i], nums[first]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        mix(nums, 0, nums.size() - 1, result);

        return result;
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 7.5 MB (92.52%)
*/