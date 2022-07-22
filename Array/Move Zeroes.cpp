// �־��� �Է� �迭 nums���� 0�� �ƴ� ���ҵ���
// ����� ����� �����ϸ鼭 0�� ��� ������ �̵��Ѵ�.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        // ���� ó�� 0�� ������ ������ ã��
        while (i < nums.size() && nums[i] != 0) i++;

        // �� ������ ���Ұ� 0�̰ų� 0�� ���� ��� �״�� return
        if (i >= nums.size() - 1)   return;

        // i�� �迭���� ó�� ������ 0�� �ε���
        // i�� ��� 0�� ��ġ�� ����Ű�� index�� ��.
        // j�� i �ٷ� ���� ��
        for (int j = i + 1; j < nums.size(); j++) {
            // j �ε����� ���Ұ� 0�� �ƴ϶��
            if (nums[j] != 0) {
                // j�� i�� ��ġ ��ȯ
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;

                // �ٽ� 0�� ������ �������� i ����
                while (i < nums.size() && nums[i] != 0) i++;

                if (i > j)  j = i + 1;
            }
        }
    }
};