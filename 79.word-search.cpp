/*
 * @lc app=leetcode id=79 lang=cpp
 * @lcpr version=21913
 *
 * [79] Word Search
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        num_rows = board.size();
        num_cols = board[0].size();
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '.';
                    if (search(word, board, 1, i, j)) {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }

   private:
    bool search(const string& word, vector<vector<char>>& board, int word_pos, int row, int col) {
        if (word_pos == word.size()) {
            return true;
        }
        const static vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& dir : dirs) {
            int r = row + dir[0];
            int c = col + dir[1];
            if (r >= 0 && r < num_rows && c >= 0 && c < num_cols && board[r][c] == word[word_pos]) {
                board[r][c] = '.';
                if (search(word, board, word_pos + 1, r, c)) {
                    return true;
                }
                board[r][c] = word[word_pos];
            }
        }
        return false;
    }

    int num_rows, num_cols;
};
// @lc code=end

/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */
