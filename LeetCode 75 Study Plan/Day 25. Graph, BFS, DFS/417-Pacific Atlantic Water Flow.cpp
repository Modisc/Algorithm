/*
* There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean.
* The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
* The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
* The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west
* if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
* Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
* 
* Example 1:
*    Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
*    Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
*    Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
*    [0,4]: [0,4] -> Pacific Ocean 
*           [0,4] -> Atlantic Ocean
*    [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
*           [1,3] -> [1,4] -> Atlantic Ocean
*    [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
*           [1,4] -> Atlantic Ocean
*    [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
*           [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
*    [3,0]: [3,0] -> Pacific Ocean 
*           [3,0] -> [4,0] -> Atlantic Ocean
*    [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
*           [3,1] -> [4,1] -> Atlantic Ocean
*    [4,0]: [4,0] -> Pacific Ocean 
*           [4,0] -> Atlantic Ocean
*    Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
* 
* Example 2:
*	Input: heights = [[1]]
*	Output: [[0,0]]
*	Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
* 
* Constraints:
*	m == heights.length
*	n == heights[r].length
*	1 <= m, n <= 200
*	0 <= heights[r][c] <= 10^5
*/

class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col, int rowSize, int colSize,
        int prevHeight, vector<vector<bool>>& reachable)
    {
        if (row < 0 || col < 0 || row >= rowSize || col >= colSize
            || heights[row][col] < prevHeight || reachable[row][col] == true)
        {
            return;
        }

        prevHeight = heights[row][col];
        reachable[row][col] = true;

        dfs(heights, row + 1, col, rowSize, colSize, prevHeight, reachable);
        dfs(heights, row - 1, col, rowSize, colSize, prevHeight, reachable);
        dfs(heights, row, col + 1, rowSize, colSize, prevHeight, reachable);
        dfs(heights, row, col - 1, rowSize, colSize, prevHeight, reachable);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rowSize = heights.size();
        int colSize = heights[0].size();
        int prevHeight = 0;
        vector<vector<bool>> pacificReachable(rowSize, vector<bool>(colSize, false));
        vector<vector<bool>> atlanticReachable(rowSize, vector<bool>(colSize, false));
        vector<vector<int>> ans;

        for (int i = 0; i < colSize; i++)
        {
            prevHeight = 0;
            dfs(heights, 0, i, rowSize, colSize, prevHeight, pacificReachable);
            dfs(heights, rowSize - 1, i, rowSize, colSize, prevHeight, atlanticReachable);
        }

        for (int i = 0; i < rowSize; i++)
        {
            prevHeight = 0;
            dfs(heights, i, 0, rowSize, colSize, prevHeight, pacificReachable);
            dfs(heights, i, colSize - 1, rowSize, colSize, prevHeight, atlanticReachable);
        }

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (pacificReachable[i][j] && atlanticReachable[i][j])
                    ans.push_back({ i, j });
            }
        }

        return ans;
    }
};
/* Time Limit Exceed
class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col, int rowSize, int colSize, int prevHeights,
                vector<vector<bool>> visited, bool& isPacificOcean, bool& isAtlanticOcean)
    {
        if(isPacificOcean && isAtlanticOcean)   return;

        if(row < 0 || col < 0)
        {
            isPacificOcean = true;
            return;
        }
        if(row >= rowSize || col >= colSize)
        {
            isAtlanticOcean = true;
            return;
        }

        if(heights[row][col] > prevHeights || visited[row][col] == true)
        {
            return;
        }

        prevHeights = heights[row][col];
        visited[row][col] = true;

        dfs(heights, row + 1, col, rowSize, colSize, prevHeights, visited, isPacificOcean, isAtlanticOcean);
        dfs(heights, row - 1, col, rowSize, colSize, prevHeights, visited, isPacificOcean, isAtlanticOcean);
        dfs(heights, row, col + 1, rowSize, colSize, prevHeights, visited, isPacificOcean, isAtlanticOcean);
        dfs(heights, row, col - 1, rowSize, colSize, prevHeights, visited, isPacificOcean, isAtlanticOcean);

        visited[row][col] = false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rowSize = heights.size();
        int colSize = heights[0].size();
        bool isPacificOcean = false;
        bool isAtlanticOcean = false;
        int prevHeights = -1;
        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
        vector<vector<int>> ans;

        for(int i = 0; i < rowSize; i++)
        {
            for(int j = 0; j < colSize; j++)
            {
                prevHeights = heights[i][j];
                dfs(heights, i, j, rowSize, colSize, prevHeights, visited, isPacificOcean, isAtlanticOcean);

                if(isPacificOcean && isAtlanticOcean)
                {
                    ans.push_back({i, j});
                }

                isPacificOcean = false;
                isAtlanticOcean = false;
            }
        }

        return ans;
    }
};*/

/*
* Result
* Time: 49 ms (57.9%), Space: 17.5 MB (76.69%)
*/