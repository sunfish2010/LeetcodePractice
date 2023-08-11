/*
 * @lc app=leetcode id=1318 lang=cpp
 * @lcpr version=21913
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution {
   public:
    int minFlips(int a, int b, int c) {
        int num_flips = 0;
        while ((a | b) != c) {
            int c_end = c & 1;
            int ab_end = (a | b) & 1;
            if (c_end != ab_end) {
                if (c_end == 1) {
                    num_flips += 1;
                } else {
                    num_flips += (a & b & 1) == 1 ? 2 : 1;
                }
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return num_flips;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n6\n5\n
// @lcpr case=end

// @lcpr case=start
// 4\n2\n7\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n3\n
// @lcpr case=end

 */
