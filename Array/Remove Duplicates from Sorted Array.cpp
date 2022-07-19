#include <iostream>
using namespace std;

// ������������ ���ĵ� �迭 nums�� �Է����� ����
// �ߺ��� ���Ҹ� �����ϰ� ���� ���Ҹ� ������ ��ܿͼ�
// ���� �� �ڸ��� ������ ���� �ְ�
// ��ȿ�� �� ������ �迭�� ���̸� ��ȯ��.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // �ߺ��Ǵ� �� ���� �� ���� ���Ҹ� ������ ���� ���� ������ ������
        // ��, �� ���� ���Ҵ� �ݵ�� 1�� �����ϰ� �ǹǷ� k = 1 ���� ������.
        // �������� �־��� ���� : -100 <= nums[i] <= 100
        int k = 1;
        for(int i = 0; i<nums.size() - 1; i++){
            if(nums[i] == nums[i+1]) nums[i] = 101;
            if(nums[i] >= -100 && nums[i] <= 100)   k++;
        }
        sort(nums.begin(), nums.end());

        return k;

        /* �ַ�� �ڵ�
        int i = 0;
        for(int j = 1; j<nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
        */
    }
};