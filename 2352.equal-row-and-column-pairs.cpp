/*
 * @lc app=leetcode id=2352 lang=cpp
 * @lcpr version=21912
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>> element_map;
        for (int i = 0; i < n; ++i) {
            element_map[grid[0][i]].push_back(i);
        }
        int num_pairs = 0;
        for (int i = 0; i < n; ++i) {
            if (element_map.find(grid[i][0]) != element_map.end()) {
                for (const auto& row : element_map[grid[i][0]]) {
                    // Check if row and col is the same.
                    bool is_same = true;
                    for (int j = 0; j < n; ++j) {
                        if (grid[j][row] != grid[i][j]) {
                            is_same = false;
                            break;
                        }
                    }
                    if (is_same) {
                        num_pairs++;
                    }
                }
            }
        }
        return num_pairs;
    }
};
/*

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        # column start map
        element_map = {}
        for i in range(n):
            if grid[0][i] not in element_map:
                element_map[grid[0][i]] = [i]
            else:
                element_map[grid[0][i]].append(i)
        num_pairs = 0
        # check the row start
        for i in range(n):
            if grid[i][0] in element_map:
                for column in element_map[grid[i][0]]:
                    num_pairs += [row[column] for row in grid] == grid[i]

        return num_pairs
*/
// @lc code=end

/*
// @lcpr case=start
// [[3,2,1],[1,7,6],[2,7,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]\n
// @lcpr case=end

 */
