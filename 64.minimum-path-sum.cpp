/*
 * @lc app=leetcode id=64 lang=cpp
 * @lcpr version=21801
 *
 * [64] Minimum Path Sum
 */
using namespace std;
#include <vector>

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid){
        // num_cols and num_rows >=1
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        for (int i = num_rows - 1; i >= 0; i--){
            for (int j = num_cols - 1; j >= 0; j--){
                if ((i == num_rows - 1) && (j == num_cols - 1)){
                    continue;
                }
                // At the right most col, can only read from bottom
                else if (j == num_cols - 1){
                    grid[i][j] += grid[i+1][j];
                }
                // At the bottom most row, can only read from right.
                else if(i == num_rows - 1){
                    grid[i][j] += grid[i][j+1];
                }
                else{
                    grid[i][j] += std::min(grid[i][j+1], grid[i+1][j]);
                }
            }
        }
        return grid[0][0];
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */
