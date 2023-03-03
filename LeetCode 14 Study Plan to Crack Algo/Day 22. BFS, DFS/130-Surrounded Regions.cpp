/*
* Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
* A region is captured by flipping all 'O's into 'X's in that surrounded region.
* 
* Example 1:
*	Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
*	Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
*	Explanation: Notice that an 'O' should not be flipped if:
*	- It is on the border, or
*	- It is adjacent to an 'O' that should not be flipped.
*	The bottom 'O' is on the border, so it is not flipped.
*	The other three 'O' form a surrounded region, so they are flipped.
* 
* Example 2:
*	Input: board = [["X"]]
*	Output: [["X"]]
* 
* Constraints:
*	m == board.length
*	n == board[i].length
*	1 <= m, n <= 200
*	board[i][j] is 'X' or 'O'.
*/

class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col, int rowSize, int colSize)
    {
        if (row < 0 || col < 0 || row >= rowSize || col >= colSize || board[row][col] != 'O')
            return;

        board[row][col] = 'A';

        dfs(board, row + 1, col, rowSize, colSize);
        dfs(board, row, col + 1, rowSize, colSize);
        dfs(board, row - 1, col, rowSize, colSize);
        dfs(board, row, col - 1, rowSize, colSize);
    }

    void solve(vector<vector<char>>& board) {
        int rowSize = board.size();
        int colSize = board[0].size();

        for (int row = 0; row < rowSize; row++)
        {
            if (board[row][0] == 'O')
                dfs(board, row, 0, rowSize, colSize);

            if (board[row][colSize - 1] == 'O')
                dfs(board, row, colSize - 1, rowSize, colSize);


        }

        for (int col = 0; col < colSize; col++)
        {
            if (board[0][col] == 'O')
                dfs(board, 0, col, rowSize, colSize);

            if (board[rowSize - 1][col] == 'O')
                dfs(board, rowSize - 1, col, rowSize, colSize);
        }


        for (int row = 0; row < rowSize; row++)
        {
            for (int col = 0; col < colSize; col++)
            {
                if (board[row][col] == 'O')
                    board[row][col] = 'X';

                else if (board[row][col] == 'A')
                    board[row][col] = 'O';
            }
        }
    }
};

/*
* Result
* Time: 14 ms (66.31%), Space: 10 MB (72.10%)
*/