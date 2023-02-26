/*
* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
* Notice that the solution set must not contain duplicate triplets.
* 
* Example 1:
*	Input: nums = [-1,0,1,2,-1,-4]
*	Output: [[-1,-1,2],[-1,0,1]]
*	Explanation: 
*	nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
*	nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
*	nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
*	The distinct triplets are [-1,0,1] and [-1,-1,2].
*	Notice that the order of the output and the order of the triplets does not matter.
* 
* Example 2:
*	Input: nums = [0,1,1]
*	Output: []
*	Explanation: The only possible triplet does not sum up to 0.
* 
* Example 3:
*	Input: nums = [0,0,0]
*	Output: [[0,0,0]]
*	Explanation: The only possible triplet sums up to 0.
* 
* Constraints:
*	3 <= nums.length <= 3000
*	-10^5 <= nums[i] <= 10^5
*/

// Two Pointer. Time: O(n*n), Space: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] > 0)    return {};
        int size = nums.size();
        int low, high;

        vector<vector<int>> ans;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] > 0)    break;

            if (i > 0 && nums[i] == nums[i - 1])     continue;

            low = i + 1;
            high = size - 1;
            while (low < high)
            {
                if (nums[i] + nums[low] + nums[high] > 0)    high--;
                else if (nums[i] + nums[low] + nums[high] < 0)   low++;
                else
                {
                    ans.push_back({ nums[i], nums[low], nums[high] });
                    int lastLowCase = nums[low], lastHighCase = nums[high];
                    while (low < high && lastLowCase == nums[low])   low++;
                    while (low < high && lastHighCase == nums[high])     high--;
                }
            }
        }

        return ans;
    }
};


/* HashMap. Time: O(n*n), Space: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] > 0)    return {};
        int size = nums.size();
        int low, high;

        unordered_map<int, int> m;
        vector<vector<int>> ans;

        for(int i = 0; i<size; i++)
        {
            m[nums[i]] = i;
            cout << m[nums[i]] << endl;
        }

        for(int i = 0; i<size - 2; i++)
        {
            if(nums[i] > 0)     break;

            if(i > 0 && nums[i] == nums[i-1])   continue;

            for(int j = i+1; j<size-1; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1])     continue;

                int key = -(nums[i] + nums[j]);
                if(m.find(key) != m.end() && m[key] > j)
                    ans.push_back({nums[i], nums[j], key});
            }
        }

        return ans;
    }
};*/

/*
* Result
* Time: 147 ms (70.11%), Space: 24 MB (77.35%)
*/