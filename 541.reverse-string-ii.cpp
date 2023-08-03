/*
 * @lc app=leetcode id=541 lang=cpp
 * @lcpr version=21913
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
   public:
    string reverseStr(string s, int k) {
    }
};
// @lc code=end

/*

class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        left = 0
        n = len(s)
        a = list(s)
        while left + 2 * k <  n:
            a[left:left+k] = a[left:left+k][::-1]
            left += 2 * k
        char_left = n - left
        if char_left >= k:
            a[left:left+k] = a[left:left+k][::-1]
        else:
            a[left:] = a[left:][::-1]
        return "".join(a)



*/

/*
// @lcpr case=start
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */
