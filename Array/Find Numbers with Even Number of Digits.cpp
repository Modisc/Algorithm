// �Է����� ���� �迭�� ���� ��
// ¦�� �ڸ����� ���� ���� �ޱ�.
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int digit = 1;
        int evenDigitCount = 0;

        // 10 �̻��� ���� �߿��� 10���� ���� Ƚ���� digit�� ����
        // digit�� 2�� ������ �������� ¦�� �ڸ��� �̹Ƿ� evenDigitCount ����.
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) >= 10) {
                int num = nums.at(i);
                while (num / 10) {
                    num /= 10;
                    digit++;
                }
                if (digit % 2 == 0) {
                    evenDigitCount++;
                }
                digit = 1;
            }
        }
        return evenDigitCount;
    }
};