/*
* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
* Find two lines that together with the x-axis form a container, such that the container contains the most water.
* Return the maximum amount of water a container can store.
* Notice that you may not slant the container.
* 
* Example 1:
*	Input: height = [1,8,6,2,5,4,8,3,7]
*	Output: 49
*	Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
* 
* Example 2:
*	Input: height = [1,1]
*	Output: 1
* 
* Constraints:
*	n == height.length
*	2 <= n <= 10^5
*	0 <= height[i] <= 10^4
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0;
        int last = height.size() - 1;
        int maxArea = 0;

        while (first < last)
        {
            int tmpArea = min(height[first], height[last]) * (last - first);
            maxArea = max(tmpArea, maxArea);

            if (height[first] > height[last])
            {
                last--;
            }
            else
            {
                first++;
            }
        }

        return maxArea;
    }
};

/*
* Result
* Time: 92 ms (85.97%), Space: 59.1 MB (56.6%)
*/