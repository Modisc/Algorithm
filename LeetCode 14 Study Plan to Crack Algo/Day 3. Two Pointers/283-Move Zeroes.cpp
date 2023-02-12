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

        // 제일 처음 0이 나오는 지점을 찾음
        while (i < nums.size() && nums[i] != 0) i++;

        // 맨 마지막 원소가 0이거나 0이 없는 경우 그대로 return
        if (i >= nums.size() - 1)   return;

        // i는 배열에서 처음 나오는 0의 인덱스
        // i는 계속 0의 위치를 가리키는 index가 됨.
        // j는 i 바로 다음 값
        for (int j = i + 1; j < nums.size(); j++) {
            // j 인덱스의 원소가 0이 아니라면
            if (nums[j] != 0) {
                // j와 i의 위치 교환
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i++] = tmp;

                // 다시 0이 나오는 지점까지 i 증가
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