/*
* You are given an m x n integer matrix matrix with the following two properties:
* Each row is sorted in non-decreasing order.
* The first integer of each row is greater than the last integer of the previous row.
* Given an integer target, return true if target is in matrix or false otherwise.
* You must write a solution in O(log(m * n)) time complexity.
* 
* Example 1:
*	Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
*	Output: true
* 
* Example 2:
*	Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
*	Output: false
* 
* Constraints:
*	m == matrix.length
*	n == matrix[i].length
*	1 <= m, n <= 100
*	-10^4 <= matrix[i][j], target <= 10^4
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int beginRow = 0, endRow = matrix.size() - 1, midRow = 0;
        if (matrix.size() > 1)
        {
            // target이 속한 행 찾기
            while (beginRow <= endRow)
            {
                midRow = beginRow + (endRow - beginRow) / 2;
                if (matrix[midRow][0] == target)    return true;
                if (matrix[midRow][0] > target)
                {
                    if (midRow != 0 && matrix[midRow - 1][matrix[midRow].size() - 1] < target)
                    {
                        return false;
                    }
                    endRow = midRow - 1;
                }
                else
                {
                    if (matrix[midRow][matrix[midRow].size() - 1] >= target)
                    {
                        break;
                    }
                    beginRow = midRow + 1;
                }
            }
        }

        int beginCol = 0, endCol = matrix[0].size() - 1, midCol = 0;
        while (beginCol <= endCol)
        {
            midCol = beginCol + (endCol - beginCol) / 2;
            if (matrix[midRow][midCol] == target)    return true;
            if (matrix[midRow][midCol] > target)    endCol = midCol - 1;
            else    beginCol = midCol + 1;
        }

        return false;
    }
};

/*
* Result
* Time: 3 ms (86.83%), Space: 9.4 MB (97.35%)
*/