// 입력으로 들어온 배열의 원소 중
// 짝수 자릿수의 원소 개수 받기.
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int digit = 1;
        int evenDigitCount = 0;

        // 10 이상인 숫자 중에서 10으로 나눈 횟수를 digit에 저장
        // digit이 2로 나뉘어 떨어지면 짝수 자릿수 이므로 evenDigitCount 증가.
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) >= 10) {
                int num = nums.at(i);
                while (num / 10) {
                    num /= 10;
                    digit++;
                }
                if (digit % 2 == 0) {
                    evenDigitCount++;
                }
                digit = 1;
            }
        }
        return evenDigitCount;
    }
};