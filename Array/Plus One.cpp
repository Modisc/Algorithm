#include <iostream>
using namespace std;

// 주어진 입력 배열 digits의 각 원소를 순서대로 10진수로 가정하고
// 해당 수에 1을 더한 후 그 값을 다시 각각 자릿수별로 원소로 나누어서 배열에 저장하여 반환함.
// 0 <= digits[i] <= 9
// digits 원소가 2개 이상일 때 선행에는 0이 오지 않음.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits.size() + 1);

        // digits[i] != 9 인 원소가 최소 1개 이상 있는 경우
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits.at(i) == 9)   digits.at(i) = 0;
            else {
                digits.at(i)++;
                return digits;
            }
        }

        // digits[i] 의 모든 원소가 9인 경우
        for (int i = 0; i < result.size(); i++) {
            if (i == 0) result.at(i) = 1;
            else {
                result.at(i) = digits.at(i - 1);
            }
        }

        return result;
    }
};