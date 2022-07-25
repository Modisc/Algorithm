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
// �ش� ���Ḯ��Ʈ�� �ڿ������� n��° ���Ҹ� �����ϰ�
// ���� ���� ���Ḯ��Ʈ�� ��带 �ٽ� ��ȯ�Ѵ�.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> ptr;
        ListNode* pA = head;
        while (pA != NULL) {
            ptr.emplace_back(pA);
            pA = pA->next;
        }
        if (ptr.size() == 0)     return NULL;
        else if (ptr.size() == 1 && n == 1)    return NULL;
        else if (ptr.size() == n) {
            pA = ptr[1];
            head = pA;
        }
        else {
            pA = ptr[ptr.size() - (n + 1)];
            pA->next = pA->next->next;
        }
        return head;

        /* Two Pointer Solution
        * ������ 2���� ����. �� ������ ���� n�� ������ �����ؼ�
        * �ϳ��� �����͸� ���� ����Ʈ�� ������ �ű�.
        * ���� �����͸� �̿��ؼ� �ڿ��� n��° ��� ����.
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
        */
    }
};