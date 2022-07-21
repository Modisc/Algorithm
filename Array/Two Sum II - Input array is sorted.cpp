// 주어진 numbers 배열의 원소 중 2개를 짝지어서 더했을 때
// target과 값이 같아지는 원소의 위치를 찾는다.

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 직접 풀이
        //         vector<int> result;

        //         for(int i = 0; i<numbers.size(); i++){
        //             for(int j = i + 1; j<numbers.size(); j++){
        //                 if(numbers[i] + numbers[j] == target){
        //                     result.emplace_back(i+1); result.emplace_back(j+1);
        //                     return result;
        //                 }
        //                 else if(numbers[i] + numbers[j] > target)   break;
        //                 else if(numbers[i] == numbers[j]) i = j;
        //             }
        //         }

        // return result;

        // 솔루션
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target)   return { i + 1, j + 1 };
            else if (numbers[i] + numbers[j] > target)   j--;
            else    i++;
        }
        return {};
    }
};