/*
 * @lc app=leetcode id=289 lang=cpp
 * @lcpr version=21913
 *
 * [289] Game of Life
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    void gameOfLife(vector<vector<int>>& board) {
        int num_rows = board.size();
        int num_cols = board[0].size();
        // -1 originally live but dies, 2 originally 0 but alive in next round.
        static const vector<vector<int>> coords = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                int live_cells = 0;
                for (const auto& coord : coords) {
                    int row = i + coord[0];
                    int col = j + coord[1];
                    if (row >= 0 && row < num_rows && col >= 0 && col < num_cols && (board[row][col] == 1 || board[row][col] == -1)) {
                        live_cells++;
                    }
                }
                if ((live_cells > 3 || live_cells < 2) && board[i][j] == 1) {
                    board[i][j] = -1;
                }
                if (live_cells == 3 && board[i][j] == 0) {
                    board[i][j] = 2;
                }
            }
        }

        for (auto& row : board) {
            for (auto& cell : row) {
                if (cell == 2) {
                    cell = 1;
                } else if (cell == -1) {
                    cell = 0;
                }
            }
        }
    };
    // @lc code=end

    /*
    // @lcpr case=start
    // [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]\n
    // @lcpr case=end

    // @lcpr case=start
    // [[1,1],[1,0]]\n
    // @lcpr case=end

     */
