/*
* Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
* 
* Example 1:
*	Input: nums = [-10,-3,0,5,9]
*	Output: [0,-3,9,-10,null,5]
*	Explanation: [0,-10,5,null,-3,null,9] is also accepted:
* 
* Example 2:
*	Input: nums = [1,3]
*	Output: [3,1]
*	Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
* 
* Constraints:
*	1 <= nums.length <= 10^4
*	-10^4 <= nums[i] <= 10^4
*	nums is sorted in a strictly increasing order.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* MakeBST(vector<int>& nums, int begin, int end)
    {
        if (begin > end)    return nullptr;

        int mid = begin + (end - begin) / 2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = MakeBST(nums, begin, mid - 1);
        node->right = MakeBST(nums, mid + 1, end);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return MakeBST(nums, 0, nums.size() - 1);
    }
};

/*
* Result
* Time: 13 ms (71.42%), Space: 21.3 MB (82.99%)
*/