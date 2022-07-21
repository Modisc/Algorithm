// 주어진 문자열 haystack에서 문자열 needle 이 처음 나타나는 index를 반환하라.
class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = haystack.find(needle);
        if (result != string::npos) {
            return result;
        }
        else {
            return -1;
        }
    }
};