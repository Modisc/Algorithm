// �Է����� ���� �迭 ���� ��
// 0�� �ϳ��� �� �����Ͽ� ������.
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // ���� ������ ���Ҵ� 0�̾ �������� ����.
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr.at(i) == 0)
            {
                for (int j = arr.size() - 1; j > i; j--) {
                    arr.at(j) = arr.at(j - 1);
                }
                i++;
                arr.at(i) = 0;
            }
        }
    }

};