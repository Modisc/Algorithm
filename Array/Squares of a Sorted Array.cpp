// �Է����� ���� �迭�� �����ؼ� �������� ����
// ��, �Է����� ���� �迭�� �������� ������
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size() - 1;

        // �Է����� ���� �迭�� �������� �����̸�
        // ����� ���� ��� ���� �� ����.
        // �迭 ���� ó���� ������ ���ʿ��� �����ϸ� ������ ū ���� �����ؼ�
        // ��� �迭�� ������ ���ҷ� �߰���.
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