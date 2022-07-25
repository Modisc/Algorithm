/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 연결리스트의 헤드가 주어졌을 때
// 해당 연결리스트에 순환이 존재하는지 확인.
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL)    return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        // 하나는 느리게, 하나는 빠르게 탐색해서 겹쳐지는 지점이 생기면 순환이 존재하는 것.
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL)  return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;

    }
};