// 주어진 입력 문자열 s에 대해서 공백과 초기 단어 순서는 유지하고 
// 각 단어의 문자 순서를 반대로 한다.
class Solution {
public:
    string reverseWords(string s) {
        // Reverse Words in a String 문제에서 문자열 전체를 뒤집는 과정만 제외하고 똑같은 방법으로 실행한다.
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