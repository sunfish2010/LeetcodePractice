/*
 * @lc app=leetcode id=1770 lang=cpp
 * @lcpr version=21913
 *
 * [1770] Maximum Score from Performing Multiplication Operations
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        // Scores[i][j] -> means have chosen i num, and j from left side.
        vector<vector<int>> scores(m + 1, vector<int>(m + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int left = i; left >= 0; left--) {
                int right = n - 1 - (i - left);
                // Choose left + next state dp[i+1][left+1]
                // CHoose right + next state dp[i+1][left]
                scores[i][left] = max(multipliers[i] * nums[left] + scores[i + 1][left + 1], multipliers[i] * nums[right] + scores[i + 1][left]);
            }
        }
        return scores[0][0];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [-5,-3,-3,-2,7,1]\n[-10,-5,3,4,6]\n
// @lcpr case=end

 */
