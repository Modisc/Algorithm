/*
* Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
* Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
* Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
* The tests are generated such that there is exactly one solution. You may not use the same element twice.
* Your solution must use only constant extra space.
* 
* Example 1:
*	Input: numbers = [2,7,11,15], target = 9
*	Output: [1,2]
*	Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
* 
* Constraints:
*	2 <= numbers.length <= 3 * 104
*	 -1000 <= numbers[i] <= 1000
*	numbers is sorted in non-decreasing order.
*	-1000 <= target <= 1000
*	The tests are generated such that there is exactly one solution.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
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

/*
* Result
* Time: 11 ms (88.19%), Space: 15.6 MB (79.52%)
*/