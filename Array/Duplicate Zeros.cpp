// 입력으로 들어온 배열 원소 중
// 0을 하나씩 더 복제하여 저장함.
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // 가장 마지막 원소는 0이어도 복제되지 않음.
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr.at(i) == 0)
            {
                for (int j = arr.size() - 1; j > i; j--) {
                    arr.at(j) = arr.at(j - 1);
                }
                i++;
                arr.at(i) = 0;
            }
        }
    }

};