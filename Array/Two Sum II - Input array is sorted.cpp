// �־��� numbers �迭�� ���� �� 2���� ¦��� ������ ��
// target�� ���� �������� ������ ��ġ�� ã�´�.

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // ���� Ǯ��
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

        // �ַ��
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