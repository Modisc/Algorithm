/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ���Ḯ��Ʈ�� ��尡 �־����� ��
// �ش� ���Ḯ��Ʈ�� ��ȯ�� �����Ѵٸ� ��ȯ�� ù��° ��带 ��ȯ
// ��ȯ�� ���ٸ� null ��ȯ
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // �÷��̵� �䳢�� �ź��� �˰���
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