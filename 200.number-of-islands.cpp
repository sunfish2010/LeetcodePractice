/*
 * @lc app=leetcode id=200 lang=cpp
 * @lcpr version=21913
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int num_islands = 0;
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (grid[i][j] == '1') {
                    num_islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return num_islands;
    }

   private:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        grid[row][col] = '0';
        static const vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (const auto dir : dirs) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            if (new_col >= 0 && new_col < num_cols && new_row >= 0 && new_row < num_rows && grid[new_row][new_col] == '1') {
                grid[new_row][new_col] = '0';
                dfs(grid, new_row, new_col);
            }
        }
    }
};

/* Python implementation
    def numIslands(self, grid: List[List[str]]) -> int:
        num_rows = len(grid)
        num_cols = len(grid[0])
        dirs = [[-1, 0], [1, 0], [0, 1], [0, -1]]
        count = 0
        for i in range(num_rows):
            for j in range(num_cols):
                if grid[i][j] == '1':
                    grid[i][j] = '0'
                    count += 1
                    to_visit = [[i, j]]
                    while len(to_visit):
                        row = to_visit[0][0]
                        col = to_visit[0][1]
                        to_visit.pop(0)
                        for dir in dirs:
                            next_row = row + dir[0]
                            next_col = col + dir[1] 
                            if 0 <= next_row < num_rows and 0 <= next_col < num_cols and grid[next_row][next_col] == '1':
                                grid[next_row][next_col] = '0'
                                to_visit.append([next_row, next_col])
        return count

*/
// @lc code=end

/*
// @lcpr case=start
// [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */
