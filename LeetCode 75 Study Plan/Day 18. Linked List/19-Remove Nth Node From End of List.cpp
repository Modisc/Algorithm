/*
* Given the head of a linked list, remove the nth node from the end of the list and return its head.
* 
* Example 1:
*	Input: head = [1,2,3,4,5], n = 2
*	Output: [1,2,3,5]
*
* Example 2:
*	Input: head = [1], n = 1
*	Output: []
* 
* Example 3:
*	Input: head = [1,2], n = 1
*	Output: [1]
* 
* Constraints:
*	The number of nodes in the list is sz.
*	1 <= sz <= 30
*	0 <= Node.val <= 100
*	1 <= n <= sz
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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Two Pointer Solution
        ListNode* first = head, * second = head;

        // first와 second의 간격을 n만큼 벌려주기 위한 반복문
        for (int i = 0; i < n; i++) first = first->next;
        if (!first) return head->next;

        // first와 second의 간격이 n이기 때문에
        // 동시에 1칸씩 움직여서 first가 마지막 노드에 도착한다면
        // second는 정확히 뒤에서 (n - 1)번째 노드에 위치한다.
        while (first->next) first = first->next, second = second->next;
        second->next = second->next->next;
        return head;

    }
};

/*
* Result
* Time: 3 ms (85.62%), Space: 10.6 MB (79.45%)
*/