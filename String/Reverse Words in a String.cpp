// �־��� �Է� ���ڿ� s�� �ܾ��� ������ �ݴ�� �Ͽ� ����Ѵ�.
// ������ �ܾ�� �ܾ� ���̿��� �����ؾ� �Ѵ�.
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int id = 0;
        int end = 0;

        // ���ڿ� ��ü�� �ݴ�� ������ �ٽ� �ܾ�鸸 �ݴ�� �����´�.
        for (int start = 0; start < s.size(); start++) {
            if (s[start] != ' ') {
                if (id != 0)    s[id++] = ' ';

                end = start;
                while (end < s.size() && s[end] != ' ') {
                    s[id++] = s[end++];
                }

                reverse(s.begin() + id - (end - start), s.begin() + id);
                start = end;
            }
        }
        // ���ڿ� �������� ������ �ִٸ� �����Ѵ�.(������ �ܾ�� �ܾ� ���̿��� �����ؾ� �Ѵ�.)
        s.erase(s.begin() + id, s.end());
        return s;
    }
};