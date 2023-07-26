/*
 * @lc app=leetcode id=680 lang=cpp
 * @lcpr version=21912
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
   public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return is_palindrome(s, left + 1, right) || is_palindrome(s, left, right - 1);
            } else {
                left++;
                right--;
            }
        }
        return true;
    }

   private:
    bool is_palindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */
