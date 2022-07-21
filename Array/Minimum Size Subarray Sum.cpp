// 합이 target보다 크거나 같은 nums의 연속된 하위 배열의 최소 길이를 반환하라. 
// 존재하지 않는다면 0을 반환한다.
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int result = INT_MAX;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                result = min(result, i - left);
                sum -= nums[left++];
            }
        }

        return result != INT_MAX ? result + 1 : 0;
    }
};