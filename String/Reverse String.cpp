// �Է� �迭 s ������
class Solution {
public:
    void reverseString(vector<char>& s) {
        //reverse(s.begin(), s.end());
        int i = 0;
        int j = s.size() - 1;
        // ù��° ���ҿ� ������ ���� �ٲ㰡�鼭 ����.
        while (i < j) {
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;

            i++;
            j--;
        }
    }
};