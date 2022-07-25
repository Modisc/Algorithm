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
// 해당 연결리스트의 홀수번째 노드들은 앞으로
// 짝수번째 노드들은 뒤로 이동한다.
// 홀수, 짝수 노드간의 관계성은 유지되어야 한다.
// 첫번째 노드는 홀수로 간주한다.
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)    return nullptr;
        ListNode* odd = head, * even = head->next, * evenHead = even;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};