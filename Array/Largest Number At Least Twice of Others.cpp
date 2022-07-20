// 입력으로 주어진 nums 배열의 원소 중
// 다른 모든 원소 보다 최소 2배 이상 큰 원소가 있으면
// 해당 원소의 index를 반환한다.
// 존재하지 않으면 -1을 반환한다.
// 0 <= nums[i] <= 100
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxID = -1, maxNum = -1;

        // nums[i] 중 최댓값의 index를 maxID에 저장함
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) > maxNum) {
                maxNum = nums.at(i);
                maxID = i;
            }
        }

        // 위에서 구한 최댓값이 다른 원소의 2배 이상이 아니라면 -1을 반환한다.
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) != maxNum && nums.at(i) * 2 > maxNum) {
                return -1;

            }
        }

        return maxID;
    }
};