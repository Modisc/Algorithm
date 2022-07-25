/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 두 개의 단일 연결리스트의 헤드 A와 헤드 B가 주어졌을 때
// 두 리스트가 교차하는 노드를 반환한다.
// 연결된 두 목록에 교차가 전혀 없으면 null을 반환합니다.
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // 두 리스트 간의 교차가 존재한다면 더 짧은 노드의 길이만큼만 조사하면 충분하다.
        int n = 0, m = 0;
        ListNode* pA = headA;
        ListNode* pB = headB;

        // 각 연결리스트의 길이를 구한다.
        while (pA != NULL) {
            pA = pA->next;
            n++;
        }

        while (pB != NULL) {
            pB = pB->next;
            m++;
        }

        int t = abs(n - m);

        // 길이가 더 긴 리스트에서 두 리스트의 길이의 차 만큼 노드를 이동한다.
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

        // 두 리스트를 비교하며 같은 노드를 방문하면 해당 노드를 반환한다.
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