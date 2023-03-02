/*
* Given a binary tree
* 
*	struct Node {
*	  int val;
*	  Node *left;
*	  Node *right;
*	  Node *next;
*	}
* 
* Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
* Initially, all next pointers are set to NULL.
* 
* Example 1:
*	Input: root = [1,2,3,4,5,null,7]
*	Output: [1,#,2,3,#,4,5,7,#]
*	Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
*	The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
* 
* Example 2:
*	Input: root = []
*	Output: []
* 
* Constraints:
*	The number of nodes in the tree is in the range [0, 6000].
*	-100 <= Node.val <= 100
* 
* Follow-up:
*	You may only use constant extra space.
*	The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// Level Order Traversal, BFS. Time: O(n), Space: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)   return nullptr;

        Node dummy(INT_MIN);

        for (Node* curr = root, *pre = &dummy; curr; curr = curr->next)
        {
            if (curr->left)
            {
                pre->next = curr->left;
                pre = pre->next;
            }
            if (curr->right)
            {
                pre->next = curr->right;
                pre = pre->next;
            }
        }

        connect(dummy.next);

        return root;
    }

};

/* Queue, BFS. Time: O(n), Space: O(n)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return nullptr;

        int n = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            n = q.size();

            for(int i = 0; i<n; i++)
            {
                Node* tmp = q.front();
                q.pop();
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    q.push(tmp->right);
                }
                if(i != n-1)    tmp->next = q.front();
            }
        }

        return root;
    }

};*/

/*
* Result
* Time: 12 ms (82.31%), Space: 17.2 MB (99.77%)
*/