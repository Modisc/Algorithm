/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 연결리스트의 헤드가 주어졌을 때
// 해당 연결리스트에 순환이 존재한다면 순환의 첫번째 노드를 반환
// 순환이 없다면 null 반환
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // 플로이드 토끼와 거북이 알고리즘
        if (head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        do {
            if (fast == NULL || fast->next == NULL)  return NULL;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        fast = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};