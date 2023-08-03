/*
 * @lc app=leetcode id=3 lang=cpp
 * @lcpr version=21913
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <ctype.h>

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> char_index;
        int res = 0;
        int left = 0;
        int right = 0;
        for (right = 0; right < s.size(); ++right) {
            if (char_index.find(s[right]) != char_index.end()) {
                res = max(right - left, res);
                left = max(left, char_index[s[right]] + 1);
            }
            char_index[s[right]] = right;
        }
        res = max(right - left, res);
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
