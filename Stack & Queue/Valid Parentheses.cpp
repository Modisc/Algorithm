// 주어진 문자열 s에 괄호 {}, [], () 이 랜덤한 순서로 주어질 때
// 해당 괄호의 배치와 숫자가 유효한지 확인하기.
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        if (s.length() == 0)     return true;
        if (s.length() == 1)   return false;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == ')' || c == '}' || c == ']') {
                if (stack.size() == 0)   return false;
                if (c == ')' && stack.top() != '(') return false;
                if (c == '}' && stack.top() != '{') return false;
                if (c == ']' && stack.top() != '[') return false;
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }

        if (stack.size() == 0)   return true;
        return false;
    }
};