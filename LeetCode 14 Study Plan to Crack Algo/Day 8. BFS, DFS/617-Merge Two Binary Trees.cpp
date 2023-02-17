/*
* You are given two binary trees root1 and root2.
* Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
* You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node.
* Otherwise, the NOT null node will be used as the node of the new tree. Return the merged tree.
* Note: The merging process must start from the root nodes of both trees.
* 
* Example 1:
*	Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
*	Output: [3,4,5,5,4,null,7]
* 
* Example 2:
*	Input: root1 = [1], root2 = [1,2]
*	Output: [2,2]
*
* Constraints:
*	The number of nodes in both trees is in the range [0, 2000].
*	-10^4 <= Node.val <= 10^4
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

 // Queue
/*class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)  return root2;
        if(!root2)  return root1;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() && !q2.empty())
        {
            TreeNode* tmp1 = q1.front();
            TreeNode* tmp2 = q2.front();
            q1.pop();
            q2.pop();

            tmp1->val += tmp2->val;

            if(!tmp1->left && tmp2->left) tmp1->left = tmp2->left;
            else if(tmp1->left && tmp2->left)
            {
                q1.push(tmp1->left);
                q2.push(tmp2->left);
            }
            if(!tmp1->right && tmp2->right) tmp1->right = tmp2->right;
            else if(tmp1->right && tmp2->right)
            {
                q1.push(tmp1->right);
                q2.push(tmp2->right);
            }
        }
        return root1;
    }
};*/

//Recursion
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1)  return root2;
        if (!root2)  return root1;

        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

/*
* Result
* Time: 35 ms (89.62%), Space: 32.4 MB (45.50%)
*/