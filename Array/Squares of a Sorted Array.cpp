// 입력으로 들어온 배열을 제곱해서 오름차순 정렬
// 단, 입력으로 들어온 배열은 오름차순 정렬임
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size() - 1;

        // 입력으로 들어온 배열이 오름차순 정렬이며
        // 양수와 음수 모두 들어올 수 있음.
        // 배열 원소 처음과 마지막 양쪽에서 접근하며 절댓값이 큰 값을 제곱해서
        // 결과 배열의 마지막 원소로 추가함.
        for (int i = nums.size() - 1; i >= 0; i--) {
            int square = 0;
            if (abs(nums.at(left)) <= abs(nums.at(right))) {
                square = nums.at(right);
                right--;
            }
            else {
                square = nums.at(left);
                left++;
            }
            result[i] = square * square;
        }

        return result;
    }
};