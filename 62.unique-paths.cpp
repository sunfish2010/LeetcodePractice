/*
 * @lc app=leetcode id=62 lang=cpp
 * @lcpr version=21913
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> unique_paths(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            unique_paths[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            unique_paths[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                unique_paths[i][j] = unique_paths[i - 1][j] + unique_paths[i][j - 1];
            }
        }
        return unique_paths[m - 1][n - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

 */
