// 파스칼 삼각형의 rowIndex 행을 반환한다.
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        result[0] = result[rowIndex] = 1;
        long temp = 1;
        // 조합을 이용한 풀이.
        // 3번째 행의 i번째 원소는 3Ci 를 이용해서 구할 수 있다.
        for (int i = 1, up = rowIndex, down = 1; i < rowIndex; i++, up--, down++) {
            temp = temp * up / down;
            result[i] = temp;
        }
        return result;
    }
};