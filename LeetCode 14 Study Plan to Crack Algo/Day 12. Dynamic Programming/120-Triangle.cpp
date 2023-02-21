/*
* Given a triangle array, return the minimum path sum from top to bottom.
* For each step, you may move to an adjacent number of the row below. More formally,
* if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
* 
* Example 1:
*	Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
*	Output: 11
*	Explanation: The triangle looks like:
*	   2
*	  3 4
*	 6 5 7
*	4 1 8 3
*	The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
* 
* Example 2:
*	Input: triangle = [[-10]]
*	Output: -10
* 
* Constraints:
*	1 <= triangle.length <= 200
*	triangle[0].length == 1
*	triangle[i].length == triangle[i - 1].length + 1
*	-104 <= triangle[i][j] <= 104
* 
* Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

// Recursive (Time Limit Exceeded)
class Solution {
public:
    int minimumVal(vector<vector<int>>& triangle, int row, int col)
    {
        if (row >= triangle.size())
            return 0;

        return triangle[row][col]
            + min(minimumVal(triangle, row + 1, col), minimumVal(triangle, row + 1, col + 1));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return minimumVal(triangle, 0, 0);
    }
};

/* top-down
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i<triangle.size(); i++)
        {
            for(int j = 0; j<=i; j++)
            {
                if(j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if(j == i)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }

        return *min_element(triangle[triangle.size()-1].begin(), triangle[triangle.size()-1].end());
    }
};*/

/*bottom-up
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        for(int i = triangle.size() - 2; i>=0; i--)
        {
            for(int j = 0; j<=i; j++)
            {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }

        return triangle[0][0];
    }
};*/

/*
* Result
* Time: 0 ms (100%), Space: 8.6 MB (81.66%)
*/