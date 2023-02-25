/*
* A peak element is an element that is strictly greater than its neighbors.
* Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
* You may imagine that nums[-1] = nums[n] = -��. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
* You must write an algorithm that runs in O(log n) time.
* 
* Example 1:
*	Input: nums = [1,2,3,1]
*	Output: 2
*	Explanation: 3 is a peak element and your function should return the index number 2.
* 
* Example 2:
*	Input: nums = [1,2,1,3,5,6,4]
*	Output: 5
*	Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
* 
* Constraints:
*	1 <= nums.length <= 1000
*	-2^31 <= nums[i] <= 2^31 - 1
*	nums[i] != nums[i + 1] for all valid i.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1, mid = 0;
        while (begin < end - 1)
        {
            mid = begin + (end - begin) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;

            if (nums[mid] > nums[mid - 1])
                begin = mid + 1;
            else
                end = mid - 1;
        }

        return nums[begin] > nums[end] ? begin : end;
    }
};

/* TIme: O(n), Space: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int pointer = 0;
        int size = nums.size();
        while(pointer < size)
        {
            if(pointer == size - 1)  return pointer;

            if(nums[pointer] < nums[pointer+1])
            {
                pointer++;
                continue;
            }

            break;
        }

        return pointer;
    }
};*/

/*
* Result
* Time: 0 ms (100%), Space: 8.8 MB (78.57%)
*/