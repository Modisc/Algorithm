// ���ڿ� �迭 �߿��� ���� �� ���� ���λ� ���ڿ� ã��
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