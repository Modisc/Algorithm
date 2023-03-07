/*
* Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
* The solution set must not contain duplicate subsets. Return the solution in any order.
* 
* Example 1:
*	Input: nums = [1,2,2]
*	Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
* 
* Example 2:
*	Input: nums = [0]
*	Output: [[],[0]]
* 
* Constraints:
*	1 <= nums.length <= 10
*	-10 <= nums[i] <= 10
*/

// Recursive
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        sort(nums.begin(), nums.end());

        GetSubsets(nums, subs, sub, 0);
        return subs;
    }

    void GetSubsets(vector<int>& nums, vector<vector<int>>& subs, vector<int>& sub, int begin)
    {
        subs.push_back(sub);
        for (int i = begin; i < nums.size(); i++)
        {
            if (i == begin || nums[i] != nums[i - 1])
            {
                sub.push_back(nums[i]);
                GetSubsets(nums, subs, sub, i + 1);
                sub.pop_back();
            }
        }
    }
};

/* Iterative
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        sort(nums.begin(), nums.end());

        int size = nums.size();
        int dupliCount;
        int subsetsSize;

        for(int i = 0; i < size;)
        {
            dupliCount = 0;
            while((dupliCount + i) < size && nums[dupliCount + i] == nums[i])   dupliCount++;

            subsetsSize = subs.size();
            for(int j = 0; j < subsetsSize; j++)
            {
                vector<int> sub = subs[j];
                for(int k = 0; k < dupliCount; k++)
                {
                    sub.push_back(nums[i]);
                    subs.push_back(sub);
                }
            }
            i += dupliCount;
        }

        return subs;
    }
};*/

/*
* Result
* Time: 3 ms (73.77%), Space: 7.6 MB (68.91%)
*/