/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// �� ���� ���� ���Ḯ��Ʈ�� ��� A�� ��� B�� �־����� ��
// �� ����Ʈ�� �����ϴ� ��带 ��ȯ�Ѵ�.
// ����� �� ��Ͽ� ������ ���� ������ null�� ��ȯ�մϴ�.
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // �� ����Ʈ ���� ������ �����Ѵٸ� �� ª�� ����� ���̸�ŭ�� �����ϸ� ����ϴ�.
        int n = 0, m = 0;
        ListNode* pA = headA;
        ListNode* pB = headB;

        // �� ���Ḯ��Ʈ�� ���̸� ���Ѵ�.
        while (pA != NULL) {
            pA = pA->next;
            n++;
        }

        while (pB != NULL) {
            pB = pB->next;
            m++;
        }

        int t = abs(n - m);

        // ���̰� �� �� ����Ʈ���� �� ����Ʈ�� ������ �� ��ŭ ��带 �̵��Ѵ�.
        if (n > m) {
            while (t) {
                headA = headA->next;
                t--;
            }
        }
        else {
            while (t) {
                headB = headB->next;
                t--;
            }
        }

        // �� ����Ʈ�� ���ϸ� ���� ��带 �湮�ϸ� �ش� ��带 ��ȯ�Ѵ�.
        while (headA != NULL && headB != NULL) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};