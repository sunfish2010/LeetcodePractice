/*
 * @lc app=leetcode id=36 lang=cpp
 * @lcpr version=21913
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int num_rows = board.size();
        int num_cols = board[0].size();
        int row_mask = 0;
        // Every column gets own mask.
        vector<int> col_mask(num_cols);
        // Square masks can be reused every 3 rows.
        vector<int> square_mask(num_cols / 3);
        for (int i = 0; i < num_rows; ++i) {
            row_mask = 0;
            // Reset every three rows.
            if (i % 3 == 0) {
                for (auto& mask : square_mask) {
                    mask = 0;
                }
            }
            for (int j = 0; j < num_cols; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int shifted = 1 << (board[i][j] - '0');
                if ((row_mask & shifted) || (col_mask[j] & shifted) || (square_mask[j / 3] & shifted)) {
                    return false;
                }
                // Mark the numbers as occurred.
                row_mask |= shifted;
                col_mask[j] |= shifted;
                square_mask[j / 3] |= shifted;
            }
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

// @lcpr case=start
// [["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */
