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
            // �������� ���ĵ� ���¿��� ���������� ȸ���� �迭�̹Ƿ�
            // �̷� ��찡 ���� �� �ִ� ���� ��� ���ĵ� ���� ���̴�.
            if (nums[begin] < nums[end]) return nums[begin];

            mid = begin + (end - begin) / 2;

            // mid�� begin���� ũ�ٴ°� begin~mid ���̴� ��� ������ �Ϸ�Ǿ� �ִٴ� ���̹Ƿ�
            // begin�� mid+1�� �Ű��ش�.
            // ���Ұ� 2�� ���� ��찡 ���� �� �����Ƿ� mid�� begin�� ���� ��쵵 ����ؾ� �Ѵ�.
            if (nums[mid] >= nums[begin])
            {
                begin = mid + 1;
            }

            // mid�� begin���� �۴ٴ°� begin ~ mid ���� ������ �Ǿ����� �ʴٴ� ���̴�.
            // ��, begin ~ mid ���̿� �ּҰ��� �ݵ�� �����Ѵٴ� �ǹ̰� �ȴ�.
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