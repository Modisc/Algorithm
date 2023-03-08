/*
* Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
* 
* Example 1:
*	Input: nums = [1,1,2]
*	Output:
*	[[1,1,2],
*	[1,2,1],
*	[2,1,1]]
* 
* Example 2:
*	Input: nums = [1,2,3]
*	Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
* 
* Constraints:
*	1 <= nums.length <= 8
*	-10 <= nums[i] <= 10
*/

class Solution {
public:
    void GetPermutations(vector<int> nums, int first, int last, vector<vector<int>>& ans)
    {
        if (first == last)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = first; i <= last; i++)
        {
            if (i == first || nums[i] != nums[first])
            {
                swap(nums[i], nums[first]);
                GetPermutations(nums, first + 1, last, ans);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        GetPermutations(nums, 0, nums.size() - 1, ans);

        return ans;
    }
};

/*
* Result
* Time: 4 ms (91.5%), Space: 9 MB (70.44%)
*/