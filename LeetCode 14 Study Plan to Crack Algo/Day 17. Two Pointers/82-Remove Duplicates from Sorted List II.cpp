/*
* Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
* 
* Example 1:
*	Input: head = [1,2,3,3,4,4,5]
*	Output: [1,2,5]
* 
* Example 2:
*	Input: head = [1,1,1,2,3]
*	Output: [2,3]
* 
* Constraints:
*	The number of nodes in the list is in the range [0, 300].
*	-100 <= Node.val <= 100
*	The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)     return nullptr;

        ListNode* ans = new ListNode(0, head);
        ListNode* prev = ans;
        ListNode* curr = head;
        int prevVal = head->val;
        while (curr != nullptr)
        {
            if ((curr->next != nullptr && curr->val == curr->next->val) || (curr != head && curr->val == prevVal))
            {
                prev->next = curr->next;
            }
            else
            {
                prev = prev->next;
            }

            prevVal = curr->val;
            curr = curr->next;
        }

        return ans->next;
    }
};

/*
* Result
* Time: 3 ms (97.99%), Space: 11.1 MB (93.12%)
*/