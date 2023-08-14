/*
 * @lc app=leetcode id=8 lang=cpp
 * @lcpr version=21913
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
   public:
    int myAtoi(string s) {
        int num = 0;
        int i = 0;
        int n = s.size();
        int sign = 1;
        while (i < n && s[i] == ' ') {
            ++i;
        }
        // "The sign can be missing".
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            // Check for overflow.
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            num = num * 10 + digit;
            i++;
        }
        return sign == 1 ? num : -num;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "42"\n
// @lcpr case=end

// @lcpr case=start
// "   -42"\n
// @lcpr case=end

// @lcpr case=start
// "4193 with words"\n
// @lcpr case=end

 */
