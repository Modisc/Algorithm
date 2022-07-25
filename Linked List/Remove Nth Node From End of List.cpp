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

// 연결리스트의 헤드가 주어졌을 때
// 해당 연결리스트의 뒤에서부터 n번째 원소를 삭제하고
// 삭제 후의 연결리스트의 헤드를 다시 반환한다.
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
        * 포인터 2개를 설정. 두 포인터 간에 n의 간격을 유지해서
        * 하나의 포인터를 먼저 리스트의 끝으로 옮김.
        * 뒤의 포인터를 이용해서 뒤에서 n번째 노드 삭제.
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
        */
    }
};