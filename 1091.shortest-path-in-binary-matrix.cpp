/*
 * @lc app=leetcode id=1091 lang=cpp
 * @lcpr version=21913
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        static const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

        // bfs on 0 cells.
        queue<pair<int, int>> nodes;
        nodes.push({0, 0});
        grid[0][0] = 1;
        int step = 0;
        while (!nodes.empty()) {
            int n = nodes.size();
            step++;
            for (int k = 0; k < n; ++k) {
                int row = nodes.front().first;
                int col = nodes.front().second;
                nodes.pop();
                for (const auto& dir : dirs) {
                    int next_row = row + dir[0];
                    int next_col = col + dir[1];
                    if (next_row >= 0 && next_col >= 0 && next_row < num_rows && next_col < num_cols && grid[next_row][next_col] == 0) {
                        grid[next_row][next_col] = 1;
                        nodes.push({next_row, next_col});
                    }
                }
            }
        }
        if (grid[num_rows - 1][num_cols - 1] == 0) {
            return -1;
        }
        return step;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[1,1,0],[1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[1,1,0],[1,1,0]]\n
// @lcpr case=end

 */
