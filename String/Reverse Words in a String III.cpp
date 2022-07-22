// �־��� �Է� ���ڿ� s�� ���ؼ� ����� �ʱ� �ܾ� ������ �����ϰ� 
// �� �ܾ��� ���� ������ �ݴ�� �Ѵ�.
class Solution {
public:
    string reverseWords(string s) {
        // Reverse Words in a String �������� ���ڿ� ��ü�� ������ ������ �����ϰ� �Ȱ��� ������� �����Ѵ�.
        int idx = 0;
        int end = 0;
        for (int start = 0; start < s.size(); start++) {
            if (s[start] != ' ') {
                if (idx != 0) s[idx++] = ' ';

                end = start;
                while (end < s.size() && s[end] != ' ') s[idx++] = s[end++];

                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                start = end;
            }
        }

        return s;
    }
};