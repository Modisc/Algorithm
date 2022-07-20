// �Է����� �־��� nums �迭�� ���� ��
// �ٸ� ��� ���� ���� �ּ� 2�� �̻� ū ���Ұ� ������
// �ش� ������ index�� ��ȯ�Ѵ�.
// �������� ������ -1�� ��ȯ�Ѵ�.
// 0 <= nums[i] <= 100
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxID = -1, maxNum = -1;

        // nums[i] �� �ִ��� index�� maxID�� ������
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) > maxNum) {
                maxNum = nums.at(i);
                maxID = i;
            }
        }

        // ������ ���� �ִ��� �ٸ� ������ 2�� �̻��� �ƴ϶�� -1�� ��ȯ�Ѵ�.
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) != maxNum && nums.at(i) * 2 > maxNum) {
                return -1;

            }
        }

        return maxID;
    }
};