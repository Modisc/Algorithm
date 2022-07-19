#include <iostream>
using namespace std;

// �Է����� ���� �迭����
// ������ 1�� �ִ� ���� ��ȯ
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxcount = 0;
        // 1�� �� count ����, �� �� ���ڸ� ������ maxcount�� ���ؼ�
        // �� ū ���ڸ� maxcount�� ����.
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == 1) {
                count++;
            }
            else {
                maxcount = maxcount >= count ? maxcount : count;
                count = 0;
            }
        }
        maxcount = maxcount >= count ? maxcount : count;
        return maxcount;
    }
};