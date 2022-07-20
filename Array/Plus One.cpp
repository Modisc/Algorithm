#include <iostream>
using namespace std;

// �־��� �Է� �迭 digits�� �� ���Ҹ� ������� 10������ �����ϰ�
// �ش� ���� 1�� ���� �� �� ���� �ٽ� ���� �ڸ������� ���ҷ� ����� �迭�� �����Ͽ� ��ȯ��.
// 0 <= digits[i] <= 9
// digits ���Ұ� 2�� �̻��� �� ���࿡�� 0�� ���� ����.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits.size() + 1);

        // digits[i] != 9 �� ���Ұ� �ּ� 1�� �̻� �ִ� ���
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits.at(i) == 9)   digits.at(i) = 0;
            else {
                digits.at(i)++;
                return digits;
            }
        }

        // digits[i] �� ��� ���Ұ� 9�� ���
        for (int i = 0; i < result.size(); i++) {
            if (i == 0) result.at(i) = 1;
            else {
                result.at(i) = digits.at(i - 1);
            }
        }

        return result;
    }
};