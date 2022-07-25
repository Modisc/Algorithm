// ���Ḯ��Ʈ�� ��尡 �־����� ��
// �ش� ���Ḯ��Ʈ�� ȸ������ �Ǻ��ؼ� true, false ��ȯ.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, * fast = head, * prev, * temp;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next; // �÷��̵� �˰����� ���� ����� �߰� ��ġ�� �� ��ġ ã��

        prev = slow, slow = slow->next, prev->next = NULL;

        while (slow) // �տ��� �ߴ� ��� ���� �˰��� �̿��ؼ� �߰� ���ĺ����� ���� ������Ŵ
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;

        fast = head, slow = prev; // fast�� ù��° ���, slow�� ������ ���

        while (slow) // �ڿ������� ��ĭ��, �տ������� ��ĭ�� �����ϸ鼭 ���� ���� ���� �������� Ȯ��.
            if (fast->val != slow->val) return false;
            else fast = fast->next, slow = slow->next;

        return true;
        // ���Ḯ��Ʈ�� ������ �������� �ʴ� ���.
    }
};