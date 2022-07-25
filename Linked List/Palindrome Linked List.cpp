// 연결리스트의 헤드가 주어졌을 때
// 해당 연결리스트가 회문인지 판별해서 true, false 반환.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, * fast = head, * prev, * temp;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next; // 플로이드 알고리즘을 통해 노드의 중간 위치와 끝 위치 찾음

        prev = slow, slow = slow->next, prev->next = NULL;

        while (slow) // 앞에서 했던 노드 반전 알고리즘 이용해서 중간 이후부터의 노드들 반전시킴
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;

        fast = head, slow = prev; // fast는 첫번째 노드, slow는 마지막 노드

        while (slow) // 뒤에서부터 한칸씩, 앞에서부터 한칸씩 전진하면서 서로 같은 값을 가지는지 확인.
            if (fast->val != slow->val) return false;
            else fast = fast->next, slow = slow->next;

        return true;
        // 연결리스트의 원형은 유지되지 않는 방법.
    }
};