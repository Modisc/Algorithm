// ���� target���� ũ�ų� ���� nums�� ���ӵ� ���� �迭�� �ּ� ���̸� ��ȯ�϶�. 
// �������� �ʴ´ٸ� 0�� ��ȯ�Ѵ�.
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