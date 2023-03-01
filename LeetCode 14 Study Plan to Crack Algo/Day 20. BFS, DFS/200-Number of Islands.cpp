/*
* Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
* An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
* 
* Example 1:
*	Input: grid = [
*		["1","1","1","1","0"],
*		["1","1","0","1","0"],
*		["1","1","0","0","0"],
*		["0","0","0","0","0"]
*	]
*	Output: 1
*
* Example 2:
*	Input: grid = [
*		["1","1","0","0","0"],
*		["1","1","0","0","0"],
*		["0","0","1","0","0"],
*		["0","0","0","1","1"]
*	]
*	Output: 3
* 
* Constraints:
*	m == grid.length
*	n == grid[i].length
*	1 <= m, n <= 300
*	grid[i][j] is '0' or '1'.
*/

class Solution {
public:
    void checkIslands(vector<vector<char>>& grid, int row, int col)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0')
        {
            return;
        }
        grid[row][col] = '0';
        checkIslands(grid, row - 1, col);
        checkIslands(grid, row + 1, col);
        checkIslands(grid, row, col - 1);
        checkIslands(grid, row, col + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    checkIslands(grid, i, j);
                }
            }
        }
        return result;
    }
};

/*
* Result
* Time: 38 ms (73.21%), Space: 12.3 MB (66.54%)
*/