// numRows�� �־����� �Ľ�Į �ﰢ���� �ش� ����� ������
// 2���� �迭�� �����Ͽ� ��ȯ�Ѵ�.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> outerResult;
        vector<int> innerResult;
        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                innerResult.emplace_back(1);
                outerResult.emplace_back(innerResult);
                innerResult.clear();
                innerResult.shrink_to_fit();
            }
            else if (i == 1) {
                innerResult.emplace_back(1);
                innerResult.emplace_back(1);
                outerResult.emplace_back(innerResult);
                innerResult.clear();
                innerResult.shrink_to_fit();
            }
            else {
                for (int j = 0; j < i + 1; j++) {
                    if (j == 0 || j == i) {
                        innerResult.emplace_back(1);
                    }
                    else {
                        int value = outerResult[i - 1][j - 1] + outerResult[i - 1][j];
                        innerResult.emplace_back(value);
                    }
                }
                outerResult.emplace_back(innerResult);
                innerResult.clear();
                innerResult.shrink_to_fit();
            }
        }

        return outerResult;
    }
};