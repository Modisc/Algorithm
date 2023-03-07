/*
* Given an integer array nums of unique elements, return all possible subsets (the power set).
* The solution set must not contain duplicate subsets. Return the solution in any order.
* 
* Example 1:
*	Input: nums = [1,2,3]
*	Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*
* Example 2:
*	Input: nums = [0]
*	Output: [[],[0]]
* 
* Constraints:
*	1 <= nums.length <= 10
*	-10 <= nums[i] <= 10
*	All the numbers of nums are unique.
*/

// Bit Manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int numsSize = nums.size(); int p = 1 << numsSize;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < numsSize; j++)
            {
                if ((i >> j) & 1)
                    subs[i].push_back(nums[j]);
            }
        }

        return subs;
    }
};

/* Iterative
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for(auto num : nums)
        {
            int size = subs.size();
            for(int i = 0; i < size; i++)
            {
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }

        return subs;
    }
};*/

/* Recursive.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        GetSubset(nums, 0, sub, subs);

        return subs;
    }

    void GetSubset(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs)
    {
        subs.push_back(sub);
        for(int j = i; j<nums.size(); j++)
        {
            sub.push_back(nums[j]);
            GetSubset(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
}; */

/*
* Result
* Time: 0 ms (100%), Space: 7 MB (88.43%)
*/