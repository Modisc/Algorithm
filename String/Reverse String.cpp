// 입력 배열 s 뒤집기
class Solution {
public:
    void reverseString(vector<char>& s) {
        //reverse(s.begin(), s.end());
        int i = 0;
        int j = s.size() - 1;
        // 첫번째 원소와 마지막 원소 바꿔가면서 진행.
        while (i < j) {
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;

            i++;
            j--;
        }
    }
};