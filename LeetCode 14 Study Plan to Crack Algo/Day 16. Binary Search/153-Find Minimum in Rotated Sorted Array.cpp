/*
* Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
* [4,5,6,7,0,1,2] if it was rotated 4 times.
* [0,1,2,4,5,6,7] if it was rotated 7 times.
* Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
* Given the sorted rotated array nums of unique elements, return the minimum element of this array.
* You must write an algorithm that runs in O(log n) time.
* 
* Example 1:
*	Input: nums = [3,4,5,1,2]
*	Output: 1
*	Explanation: The original array was [1,2,3,4,5] rotated 3 times.
* 
* Example 2:
*	Input: nums = [4,5,6,7,0,1,2]
*	Output: 0
*	Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
* 
* Example 3:
*	Input: nums = [11,13,15,17]
*	Output: 11
*	Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
* 
* Constraints:
*	n == nums.length
*	1 <= n <= 5000
*	-5000 <= nums[i] <= 5000
*	All the integers of nums are unique.
*	nums is sorted and rotated between 1 and n times.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1, mid = 0;

        while (begin < end)
        {
            // 오름차순 정렬된 상태에서 오른쪽으로 회전한 배열이므로
            // 이런 경우가 나올 수 있는 것은 모두 정렬된 상태 뿐이다.
            if (nums[begin] < nums[end]) return nums[begin];

            mid = begin + (end - begin) / 2;

            // mid가 begin보다 크다는건 begin~mid 사이는 모두 정렬이 완료되어 있다는 뜻이므로
            // begin을 mid+1로 옮겨준다.
            // 원소가 2개 뿐일 경우가 있을 수 있으므로 mid와 begin이 같은 경우도 고려해야 한다.
            if (nums[mid] >= nums[begin])
            {
                begin = mid + 1;
            }

            // mid가 begin보다 작다는건 begin ~ mid 사이 정렬이 되어있지 않다는 뜻이다.
            // 즉, begin ~ mid 사이에 최소값이 반드시 존재한다는 의미가 된다.
            else
            {
                end = mid;
            }
        }
        return nums[begin];
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 10.1 MB (97.87%)
*/