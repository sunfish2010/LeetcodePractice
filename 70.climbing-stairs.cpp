/*
 * @lc app=leetcode id=70 lang=cpp
 * @lcpr version=21912
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int two_steps_away = 1;
        int one_step_away = 2;
        for (int i = 3; i < n; ++i) {
            int curr = two_steps_away + one_step_away;
            two_steps_away = one_step_away;
            one_step_away = curr;
        }
        return one_step_away;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
