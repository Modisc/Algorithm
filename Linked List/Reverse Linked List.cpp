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

// ���Ḯ��Ʈ�� ��尡 �־����� ��
// �ش� ����Ʈ�� �ݴ�� ������
// ������ ����Ʈ�� ��带 ��ȯ.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ex) ���Ḯ��Ʈ�� ������ ������ ���ٸ� 1->2->3->null
        // null <- 1 <- 2 <- 3 �� ���� ������ �� 3�� ��ȯ�ϴ� ��.
        // ��� ��ġ�� �ٲٴ°� �ƴ϶� ����Ű�� ������ �ٲٴ� �������� ������.
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* nextTmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTmp;
        }

        return prev;
    }
};