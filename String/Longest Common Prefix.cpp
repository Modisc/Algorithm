// 문자열 배열 중에서 가장 긴 공통 접두사 문자열 찾기
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string result = str[0];

        for (int i = 1; i < str.size(); i++) {
            int j;
            for (j = 0; j < str[i].size(); j++) {
                if (result[j] != str[i][j]) break;
            }

            result = result.substr(0, j);
            if (result == "") return "";
        }
        return result;
    }
};