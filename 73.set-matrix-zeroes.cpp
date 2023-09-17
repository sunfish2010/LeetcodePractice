/*
 * @lc app=leetcode id=73 lang=cpp
 * @lcpr version=21913
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> cols;
        unordered_set<int> rows;
        int num_rows = matrix.size();
        int num_cols = matrix[0].size();
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (int i = 0; i < num_rows; ++i) {
            bool set_zero = rows.find(i) != rows.end();
            for (int j = 0; j < num_cols; ++j) {
                if (set_zero || cols.find(j) != cols.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n
// @lcpr case=end

 */
