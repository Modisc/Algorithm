/*
* Given an m x n grid of characters board and a string word, return true if word exists in the grid.
* The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
* 
* Example 1:
*	Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
*	Output: true
* 
* Example 2:
*	Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
*	Output: true
* 
* Example 3:
*	Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
*	Output: false
* 
* Constraints:
*	m == board.length
*	n = board[i].length
*	1 <= m, n <= 6
*	1 <= word.length <= 15
*	board and word consists of only lowercase and uppercase English letters.
* 
* Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int wordPointer,
        int rowSize, int colSize, int wordLength)
    {
        if (wordPointer >= wordLength)
        {
            return true;
        }

        if (row < 0 || col < 0 || row >= rowSize || col >= colSize || board[row][col] != word[wordPointer])
        {
            return false;
        }

        board[row][col] = '#';

        if (dfs(board, word, row + 1, col, wordPointer + 1, rowSize, colSize, wordLength) ||
            dfs(board, word, row - 1, col, wordPointer + 1, rowSize, colSize, wordLength) ||
            dfs(board, word, row, col + 1, wordPointer + 1, rowSize, colSize, wordLength) ||
            dfs(board, word, row, col - 1, wordPointer + 1, rowSize, colSize, wordLength))
        {
            return true;
        }

        board[row][col] = word[wordPointer];

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rowSize = board.size();
        int colSize = board[0].size();
        int wordLength = word.length();
        int wordPointer = 0;

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (board[i][j] == word[wordPointer])
                    if (dfs(board, word, i, j, wordPointer, rowSize, colSize, wordLength))
                        return true;
            }
        }

        return false;
    }
};

/*
* Result
* Time: 314 ms (95.52%), Space: 8.1 MB (24.40%)
*/