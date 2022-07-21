// 짝수 개의 정수 원소를 가진 배열 nums가 입력으로 주어질 때
// nums의 모든 원소들을 2개씩 짝지어서
// min(nums[i], nums[j])의 합이 최대가 되는 값을 구하라.

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};