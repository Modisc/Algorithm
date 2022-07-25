/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ���Ḯ��Ʈ�� ��尡 �־����� ��
// �ش� ���Ḯ��Ʈ�� ��ȯ�� �����ϴ��� Ȯ��.
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL)    return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        // �ϳ��� ������, �ϳ��� ������ Ž���ؼ� �������� ������ ����� ��ȯ�� �����ϴ� ��.
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL)  return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;

    }
};