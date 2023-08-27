/*
 * @lc app=leetcode id=221 lang=cpp
 * @lcpr version=21913
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int num_rows = matrix.size();
        int num_cols = num_rows > 0 ? matrix[0].size() : 0;
        vector<int> max_squares(num_cols + 1, 0);
        int prev = 0;
        // dp[i][j] representing the side length of square with right bottom corner at i, j
        // Pad array to deal with dp[i-1][j-1]
        /* Notice the transition from 2d to 1d. only need previous row and previous entry.
        if (matrix[i - 1][j - 1] == '1') {
            max_squares[i][j] = min(min(max_squares[i][j - 1], max_squares[i - 1][j]), max_squares[i - 1][j - 1]) + 1;
            max_length = max(max_length, max_squares[i][j]);
        }

        */
        int max_length = 0;
        for (int i = 1; i <= num_rows; ++i) {
            for (int j = 1; j <= num_cols; ++j) {
                int tmp = max_squares[j];
                if (matrix[i - 1][j - 1] == '1') {
                    max_squares[j] = min(min(prev, tmp), max_squares[j - 1]) + 1;
                    max_length = max(max_length, max_squares[j]);
                } else {
                    // reset
                    max_squares[j] = 0;
                }
                prev = tmp;
            }
        }
        return max_length * max_length;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0","1"],["1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

 */
