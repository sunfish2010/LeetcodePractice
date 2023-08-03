/*
 * @lc app=leetcode id=344 lang=cpp
 * @lcpr version=21913
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
   public:
    void reverseString(vector<char>& s) {
    }
};
// @lc code=end

/*

    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        left = 0
        right = len(s) - 1
        while left < right:
            tmp = s[left]
            s[left] = s[right]
            s[right] = tmp
            left += 1
            right -= 1

        # Note this won't work
        # s = s[::-1]
        # when assignment happens, the object's id changed
        # essentially using extra memory



*/
/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */
