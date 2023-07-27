/*
 * @lc app=leetcode id=994 lang=cpp
 * @lcpr version=21912
 *
 * [994] Rotting Oranges
 */

// @lc code=start
#include <pair>
#include <stack>
#include <vector>
using namespace std;

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        // find all rotten oranges. record indices on a queue
        // while queue is not empty, visit the neighbors one by one while keep a record of what has been visited (rotten).
        // When queue is empty, check if there's still fresh oranges.
        // Use queue over stack help record the minutes.
        queue<pair<int, int>> rotten_oranges;
        int num_row = grid.size();
        int num_col = grid[0].size();
        // helpers.
        static vector<pair<int, int>> neighbor_coords = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        static const auto in_bound = [&num_row, &num_col](int x, int y) {
            return x >= 0 && x < num_row && y >= 0 && y < num_col;
        };
        // construction
        int num_fresh_oranges = 0;
        for (int i = 0; i < num_row; ++i) {
            for (int j = 0; j < num_col; ++j) {
                if (grid[i][j] == 2) {
                    rotten_oranges.push({i, j});
                } else if (grid[i][j] == 1) {
                    num_fresh_oranges++;
                }
            }
        }
        if (rotten_oranges.empty()) {
            if (num_fresh_oranges) {
                return -1;
            }
            return 0;
        }
        // bfs
        // Use {-1, -1} to mark the level has ended.
        // Minutes start with -1 to deal with inital rotten oranges as 0.
        int minutes = -1;
        rotten_oranges.push({-1, -1});
        while (!rotten_oranges.empty()) {
            const auto coords = rotten_oranges.front();
            rotten_oranges.pop();
            int i = coords.first;
            int j = coords.second;
            if (i == -1) {
                minutes++;
                if (!rotten_oranges.empty()) {
                    rotten_oranges.push({-1, -1});
                }
                continue;
            }
            for (const auto& [di, dj] : neighbor_coords) {
                int x = di + i;
                int y = dj + j;
                // Push the neighbors if it's a valid cell, contains orange, and has not been rotten.
                if (in_bound(x, y) && grid[x][y] != 0 && grid[x][y] != 2) {
                    rotten_oranges.push({x, y});
                    grid[x][y] = 2;
                    num_fresh_oranges--;
                }
            }
        }
        if (num_fresh_oranges) {
            return -1;
        }
        return minutes;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */
