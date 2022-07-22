// �־��� �迭 nums�� ���������� k�� �̵��Ѵ�.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rotateNum = k % nums.size();
        if (rotateNum != 0) {
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + rotateNum);
            reverse(nums.begin() + rotateNum, nums.end());
        }

        // Time Limit Exceeded
        // for(int count = 0; count < rotateNum; count++){
        //     int tmp = nums[nums.size()-1];
        //     for(int i = nums.size()-1; i>0; i--){
        //         nums[i] = nums[i-1];
        //     }
        //     nums[0] = tmp;
        // }


    }
};