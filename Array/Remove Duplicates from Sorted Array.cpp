#include <iostream>
using namespace std;

// 오름차순으로 정렬된 배열 nums가 입력으로 들어옴
// 중복된 원소를 제거하고 뒤의 원소를 앞으로 당겨와서
// 뒤의 빈 자리엔 쓰레기 값을 넣고
// 유효한 값 까지의 배열의 길이를 반환함.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // 중복되는 두 원소 중 앞의 원소를 정해진 범위 밖의 값으로 변경함
        // 즉, 맨 뒤의 원소는 반드시 1개 존재하게 되므로 k = 1 에서 시작함.
        // 문제에서 주어진 조건 : -100 <= nums[i] <= 100
        int k = 1;
        for(int i = 0; i<nums.size() - 1; i++){
            if(nums[i] == nums[i+1]) nums[i] = 101;
            if(nums[i] >= -100 && nums[i] <= 100)   k++;
        }
        sort(nums.begin(), nums.end());

        return k;

        /* 솔루션 코드
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