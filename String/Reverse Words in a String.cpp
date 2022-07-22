// 주어진 입력 문자열 s를 단어의 순서를 반대로 하여 출력한다.
// 공백은 단어와 단어 사이에만 존재해야 한다.
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int id = 0;
        int end = 0;

        // 문자열 전체를 반대로 뒤집고 다시 단어들만 반대로 뒤집는다.
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
        // 문자열 마지막에 공백이 있다면 제거한다.(공백은 단어와 단어 사이에만 존재해야 한다.)
        s.erase(s.begin() + id, s.end());
        return s;
    }
};