// ¦�� ���� ���� ���Ҹ� ���� �迭 nums�� �Է����� �־��� ��
// nums�� ��� ���ҵ��� 2���� ¦���
// min(nums[i], nums[j])�� ���� �ִ밡 �Ǵ� ���� ���϶�.

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