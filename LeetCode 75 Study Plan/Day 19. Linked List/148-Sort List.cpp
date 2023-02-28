/*
* Given the head of a linked list, return the list after sorting it in ascending order.
* 
* Example 1:
*	Input: head = [4,2,1,3]
*	Output: [1,2,3,4]
* 
* Example 2:
*	Input: head = [-1,5,3,4,0]
*	Output: [-1,0,3,4,5]
* 
* Example 3:
*	Input: head = []
*	Output: []
* 
* Constraints:
*	The number of nodes in the list is in the range [0, 5 * 10^4].
*	-10^5 <= Node.val <= 10^5
* 
* Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* curr = new ListNode(0);
        ListNode* tmp = curr;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1)  curr->next = l1;
        else if (l2)  curr->next = l2;

        return tmp->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)    return head;

        ListNode* slow = head, * fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = nullptr;

        return merge(sortList(head), sortList(fast));
    }
};

/*
* Result
* Time: 227 ms (51.4%), Space: 74.2 MB (11.3%)
*/