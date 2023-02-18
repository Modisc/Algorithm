/*
* Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
* The distance between two adjacent cells is 1.
* 
* Example 1:
*	Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
*	Output: [[0,0,0],[0,1,0],[0,0,0]]
* 
* Example 2:
*	Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
*	Output: [[0,0,0],[0,1,0],[1,2,1]]
* 
* Constraints:
*	m == mat.length
*	n == mat[i].length
*	1 <= m, n <= 10^4
*	1 <= m * n <= 10^4
*	mat[i][j] is either 0 or 1.
*	There is at least one 0 in mat.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // min 함수에서 +1 을 하게되므로 INT_MAX가 아닌 INT_MAX - 10000 을 사용함.
        // 1만 빼줘도 되지만 예상치 못한 오류를 대비함.
        vector<vector<int>> result(mat.size(), vector<int>(mat[0].size(), INT_MAX - 10000));
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                    result[i][j] = 0;
                else
                {
                    if (i > 0) result[i][j] = min(result[i][j], result[i - 1][j] + 1);
                    if (j > 0) result[i][j] = min(result[i][j], result[i][j - 1] + 1);
                }
            }
        }

        for (int i = mat.size() - 1; i >= 0; i--)
        {
            for (int j = mat[0].size() - 1; j >= 0; j--)
            {
                if (i < mat.size() - 1)  result[i][j] = min(result[i][j], result[i + 1][j] + 1);
                if (j < mat[0].size() - 1)  result[i][j] = min(result[i][j], result[i][j + 1] + 1);
            }
        }

        return result;
    }
};

/*
* Result
* Time: 76 ms (88.75%), Space: 27.6 MB (81.77%)
*/
