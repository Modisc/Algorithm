/*
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* You can return the answer in any order.
* 
* Example 1:
*	Input: nums = [2,7,11,15], target = 9
*	Output: [0,1]
*	Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
* 
* Example 2:
*	Input: nums = [3,2,4], target = 6
*	Output: [1,2]
* 
* Example 3:
*	Input: nums = [3,3], target = 6
*	Output: [0,1]
* 
* Constraints:
*	2 <= nums.length <= 10^4
*	-10^9 <= nums[i] <= 10^9
*	-10^9 <= target <= 10^9
*	Only one valid answer exists.
* 
* Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size();
        vector<pair<int, int>> map(n, { -1, -1 });
        for (int i = 0; i < n; i++)
        {
            map[i].first = nums[i];
            map[i].second = i;
        }

        sort(map.begin(), map.end());
        while (left < right)
        {
            if (map[left].first + map[right].first == target)    return { map[left].second, map[right].second };
            else if (map[left].first + map[right].first > target)   right--;
            else    left++;
        }

        return {};
    }
};

/* Hash, One-Path, Optimized Code
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }

        return {-1, -1};
    }
};
*/

/*
* Result
* Time: 14 ms (71.77%), Space: 10.7 MB (45.49%)
*/