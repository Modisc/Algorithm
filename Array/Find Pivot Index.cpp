// 배열 nums가 입력으로 들어왔을 때
// 왼쪽과 오른쪽의 합이 같게 하는 pivot index 구하기
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //         int leftSum = 0, rightSum = 0, pivot = -1;

        //         for(int i = 0; i<nums.size(); i++){
        //             for(int j = i-1; j>=0; j--){
        //                 leftSum += nums.at(j);
        //             }
        //             for(int z = i+1; z<nums.size(); z++){
        //                 rightSum += nums.at(z);
        //             }
        //             if(leftSum == rightSum)
        //             {
        //                 pivot = i;
        //                 break;
        //             }
        //             leftSum = 0;
        //             rightSum = 0;
        //         }

        //         return pivot;

        int sum = 0, leftSum = 0, pivot = -1;

        for (int i = 0; i < nums.size(); i++)  sum += nums.at(i);

        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == sum - leftSum - nums.at(i)) {
                pivot = i;
                break;
            }
            leftSum += nums.at(i);
        }
        return pivot;
    }
};