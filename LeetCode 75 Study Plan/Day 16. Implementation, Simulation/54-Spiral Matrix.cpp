/*
* Given an m x n matrix, return all elements of the matrix in spiral order.
* 
* Example 1:
*	Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
*	Output: [1,2,3,6,9,8,7,4,5]
* 
* Example 2:
*	Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
*	Output: [1,2,3,4,8,12,11,10,9,5,6,7]
* 
* Constraints:
*	m == matrix.length
*	n == matrix[i].length
*	1 <= m, n <= 10
*	-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<int> ans(rowSize * colSize, INT_MAX);
        int colPointer = 0;
        int rowPointer = 0;
        int ansPointer = 0;

        while (ansPointer < rowSize * colSize)
        {
            while (colPointer < colSize && matrix[rowPointer][colPointer] != INT_MAX)
            {
                ans[ansPointer++] = matrix[rowPointer][colPointer];
                matrix[rowPointer][colPointer] = INT_MAX;
                colPointer++;
            }

            colPointer--;
            rowPointer++;

            while (rowPointer < rowSize && matrix[rowPointer][colPointer] != INT_MAX)
            {
                ans[ansPointer++] = matrix[rowPointer][colPointer];
                matrix[rowPointer][colPointer] = INT_MAX;
                rowPointer++;
            }

            rowPointer--;
            colPointer--;

            while (colPointer >= 0 && matrix[rowPointer][colPointer] != INT_MAX)
            {
                ans[ansPointer++] = matrix[rowPointer][colPointer];
                matrix[rowPointer][colPointer] = INT_MAX;
                colPointer--;
            }

            colPointer++;
            rowPointer--;

            while (rowPointer >= 0 && matrix[rowPointer][colPointer] != INT_MAX)
            {
                ans[ansPointer++] = matrix[rowPointer][colPointer];
                matrix[rowPointer][colPointer] = INT_MAX;
                rowPointer--;
            }

            rowPointer++;
            colPointer++;
        }
        return ans;
    }
};

/*
* Result
* Time: 0 ms (100%), Space: 6.7 MB (92.77%)
*/