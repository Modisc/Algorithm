// numRows가 주어지면 파스칼 삼각형의 해당 행까지 값들을
// 2차원 배열로 저장하여 반환한다.
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