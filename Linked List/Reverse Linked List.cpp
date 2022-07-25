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
// 해당 리스트를 반대로 뒤집고
// 뒤집은 리스트의 헤드를 반환.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ex) 연결리스트의 구조가 다음과 같다면 1->2->3->null
        // null <- 1 <- 2 <- 3 과 같이 변형한 후 3을 반환하는 것.
        // 노드 위치를 바꾸는게 아니라 가리키는 방향을 바꾸는 느낌으로 진행함.
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