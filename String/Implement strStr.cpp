// �־��� ���ڿ� haystack���� ���ڿ� needle �� ó�� ��Ÿ���� index�� ��ȯ�϶�.
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