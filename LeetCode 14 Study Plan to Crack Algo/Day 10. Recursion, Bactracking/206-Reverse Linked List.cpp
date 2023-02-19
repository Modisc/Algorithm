/*
* Given the head of a singly linked list, reverse the list, and return the reversed list.
* Example 1:
*   Input: head = [1,2,3,4,5]
*   Output: [5,4,3,2,1]
* 
* Example 2:
*   Input: head = []
*   Output: []
* 
* Constraints:
*    The number of nodes in the list is the range [0, 5000].
*    -5000 <= Node.val <= 5000
*/

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

 // 1 -> 2 -> 3 -> 4 -> 5 ����
 // 1 <- 2 <- 3 <- 4 <- 5 �� �ǵ���
 // ��带 �����°� �ƴ϶�, ������ ����Ű�� ������ �����´�.
 // Ǯ�� : https://leetcode.com/problems/reverse-linked-list/solutions/803955/c-iterative-vs-recursive-solutions-compared-and-explained-99-time-85-space/
 // ���̵�� ����س���
 // ����Լ� Solution�� �����ϸ� ������
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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

/*
* Result
* Time: 7 ms (70.60%), Space: 8.4 MB (20.16%)
*/