/*
* Given the head of a linked list, return the node where the cycle begins.If there is no cycle, return null.
* There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
* Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
* Do not modify the linked list.
* 
* Example 1:
*	Input: head = [3,2,0,-4], pos = 1
*	Output: tail connects to node index 1
*	Explanation: There is a cycle in the linked list, where tail connects to the second node.
* 
* Example 2:
*	Input: head = [1], pos = -1
*	Output: no cycle
*	Explanation: There is no cycle in the linked list.
* 
* Constraints:
*	The number of the nodes in the list is in the range [0, 104].
*	-105 <= Node.val <= 105
*	pos is -1 or a valid index in the linked-list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // 플로이드 토끼와 거북이 알고리즘
        if (head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        do {
            if (fast == nullptr || fast->next == nullptr)  return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

/*
* Result
* Time: 7 ms (88%), Space: 7.6 MB (68.25%)
*/