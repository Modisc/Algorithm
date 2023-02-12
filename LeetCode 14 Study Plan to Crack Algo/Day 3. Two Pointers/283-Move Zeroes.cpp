/*
* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
* Note that you must do this in-place without making a copy of the array.
* 
* Example 1:
*    Input: nums = [0,1,0,3,12]
*    Output: [1,3,12,0,0]
* 
* Example 2:
*    Input: nums = [0]
*    Output: [0]
* 
* Constraints:
*    1 <= nums.length <= 104
*    -231 <= nums[i] <= 231 - 1
*/

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
                nums[i++] = tmp;

                // �ٽ� 0�� ������ �������� i ����
                while (i < nums.size() && nums[i] != 0) i++;

                if (i > j)  j = i + 1;
            }
        }
    }
};

/*
* Result
* Time: 28 ms (52.58%), Space: 19.2 MB (86.68%)
*/