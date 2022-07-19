#include <iostream>
using namespace std;

// 입력으로 들어온 배열에서
// 연속한 1의 최대 개수 반환
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxcount = 0;
        // 1일 때 count 증가, 그 외 숫자를 만나면 maxcount와 비교해서
        // 더 큰 숫자를 maxcount에 저장.
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