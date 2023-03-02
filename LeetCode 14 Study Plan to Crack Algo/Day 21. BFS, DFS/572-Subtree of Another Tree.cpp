/*
* Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
* A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
* 
* Example 1:
*	Input: root = [3,4,5,1,2], subRoot = [4,1,2]
*	Output: true
* 
* Example 2:
*	Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
*	Output: false
* 
* Constraints:
*	The number of nodes in the root tree is in the range [1, 2000].
*	The number of nodes in the subRoot tree is in the range [1, 1000].
*	-10^4 <= root.val <= 10^4
*	-10^4 <= subRoot.val <= 10^4
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)   return false;

        if (isIdentical(root, subRoot))  return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* node1, TreeNode* node2)
    {
        if (node1 == nullptr || node2 == nullptr)
            return node1 == nullptr && node2 == nullptr;

        return node1->val == node2->val && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
    }
};

/*
* Result
* Time: 17 ms (95.36%), Space: 28.8 MB (85.32%)
*/