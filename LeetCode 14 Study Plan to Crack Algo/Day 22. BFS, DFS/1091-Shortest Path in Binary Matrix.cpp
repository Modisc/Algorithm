/*
* Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
* A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
* All the visited cells of the path are 0.
* All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
* The length of a clear path is the number of visited cells of this path.
* 
* Example 1:
*	Input: grid = [[0,1],[1,0]]
*	Output: 2
* 
* Example 2:
*	Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
*	Output: 4
* 
* Example 3:
*	Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
*	Output: -1
* 
* Constraints:
*	n == grid.length
*	n == grid[i].length
*	1 <= n <= 100
*	grid[i][j] is 0 or 1
*/

class Solution {
public:
    vector<pair<int, int>> dir = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] || grid.back().back()) return -1;

        int res = 2, len = 1, size = grid.size();
        queue<pair<int, int>> q;

        if (size == 1) return 1 - (grid[0][0] << 1);

        q.push({ 0, 0 });

        grid[0][0] = -1;
        while (len) {
            while (len--) {
                auto [cx, cy] = q.front();
                q.pop();
                for (auto x : dir)
                {
                    int row = cx + x.first;
                    int col = cy + x.second;

                    if (row < 0 || col < 0 || row >= size || col >= size)  continue;

                    if (row == (size - 1) && col == (size - 1))  return res;

                    if (!grid[row][col])
                    {
                        grid[row][col] = -1;
                        q.push({ row,col });
                    }
                }
            }

            res++;
            len = q.size();
        }

        return -1;
    }
};

/*
* Result
* Time: 56 ms (97.25%), Space: 19.2 MB (91.8%)
*/