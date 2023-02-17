/*
* Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
* 
* Example 1:
*	Input: root = [3,9,20,null,null,15,7]
*	Output: [[3],[9,20],[15,7]]
* 
* Example 2:
*	Input: root = [1]
*	Output: [[1]]
* 
* Example 3:
*	Input: root = []
*	Output: []
* 
* Constraints:
*	The number of nodes in the tree is in the range [0, 2000].
*	-1000 <= Node.val <= 1000
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)   return {};
        vector<int> subset;
        vector<vector<int>> result;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == nullptr)
            {
                result.push_back(subset);
                subset.clear();
                vector<int>().swap(subset);
                if (q.size() > 0)
                    q.push(nullptr);
            }
            else
            {
                subset.push_back(temp->val);
                if (temp->left)  q.push(temp->left);
                if (temp->right)     q.push(temp->right);
            }
        }
        return result;
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 12.6 MB (65.75%)
*/