// 주어진 배열에서 val 값을 제거하고 뒤의 원소를 앞으로 당겨옴
// 뒤쪽의 빈 자리엔 쓰레기 값이 들어감
// 쓰레기 값이 아닌 유효한 값 까지의 배열의 길이를 반환함.
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};