/*
 * @lc app=leetcode id=54 lang=cpp
 * @lcpr version=21913
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <vector>
using namespace std;

constexpr int VISITED = -101;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        static vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int curr_row = 0;
        int curr_col = 0;
        int num_rows = matrix.size();
        int num_cols = matrix[0].size();
        int dir = 0;
        int num_elements = num_cols * num_rows;
        vector<int> elements;
        while (elements.size() < num_elements) {
            elements.push_back(matrix[curr_row][curr_col]);
            matrix[curr_row][curr_col] = VISITED;
            int next_row = curr_row + dirs[dir][0];
            int next_col = curr_col + dirs[dir][1];
            if (next_col == num_cols || next_col < 0 || next_row < 0 || next_row == num_rows || matrix[next_row][next_col] == VISITED) {
                dir = (dir + 1) % dirs.size();
                next_row = curr_row + dirs[dir][0];
                next_col = curr_col + dirs[dir][1];
            }
            curr_row = next_row;
            curr_col = next_col;
        }
        return elements;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */
