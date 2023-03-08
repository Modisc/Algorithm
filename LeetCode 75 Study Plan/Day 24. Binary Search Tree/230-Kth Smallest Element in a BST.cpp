/*
* Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
* 
* Example 1:
*	Input: root = [3,1,4,null,2], k = 1
*	Output: 1
* 
* Example 2:
*	Input: root = [5,3,6,2,4,null,null,1], k = 3
*	Output: 3
* 
* Constraints:
*	The number of nodes in the tree is n.
*	1 <= k <= n <= 10^4
*	0 <= Node.val <= 10^4
* 
* Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;

        while (true)
        {
            while (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            if (--k == 0)    return root->val;
            root = root->right;
        }
    }
};

/* Recursive. Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> ans;

    void Inorder(TreeNode* root)
    {
        if(root != nullptr)
        {
            Inorder(root->left);
            ans.push_back(root->val);
            Inorder(root->right);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        Inorder(root);
        return ans[k-1];
    }
};*/

/*
* Result
* Time: 15 ms (87.46%), Space: 24.2 MB (68.49%)
*/