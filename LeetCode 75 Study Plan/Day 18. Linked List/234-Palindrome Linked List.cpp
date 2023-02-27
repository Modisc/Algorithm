/*
* Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
* 
* Example 1:
*	Input: head = [1,2,2,1]
*	Output: true
* 
* Example 2:
*	Input: head = [1,2]
*	Output: false
* 
* Constraints:
*	The number of nodes in the list is in the range [1, 10^5].
*	0 <= Node.val <= 9
* 
* Follow up: Could you do it in O(n) time and O(1) space?
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

 // Reverse. Time: O(n), Space: O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // mid 찾기
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 중간부터 reverse
        ListNode* mid = slow, * prev = nullptr, * tmp = nullptr;
        while (mid != nullptr)
        {
            tmp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = tmp;
        }

        // 처음과 끝 하나씩 값 비교
        ListNode* curr = head;
        while (curr && prev)
        {
            if (curr->val != prev->val)  return false;
            curr = curr->next;
            prev = prev->next;
        }

        return true;
    }
};


/* Stack. Time: O(n), Space: O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;

        stack<ListNode*> st;

        while(curr!=nullptr)
        {
            st.push(curr);
            curr = curr->next;
        }

        curr = head;
        while(curr != nullptr)
        {
            if(curr->val != st.top()->val)  return false;
            curr = curr->next;
            st.pop();
        }

        return true;
    }
};*/

/*
* Result
* Time: 223 ms (88.11%), Space: 114.2 MB (85.99%)
*/