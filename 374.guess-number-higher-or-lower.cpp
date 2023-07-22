/*
 * @lc app=leetcode id=374 lang=cpp
 * @lcpr version=21909
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
   public:
    // binary search
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int num = left + (right - left) / 2;
            int result = guess(num);
            if (result == 0) {
                return num;
            } else if (result > 0) {
                left = num + 1;
            } else {
                right = num - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 10\n6\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

 */
