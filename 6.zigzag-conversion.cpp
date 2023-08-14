/*
 * @lc app=leetcode id=6 lang=cpp
 * @lcpr version=21913
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string result;
        size_t n = s.size();
        size_t chars_per_section = 2 * (numRows - 1);

        for (int row = 0; row < numRows; ++row) {
            size_t index = row;
            while (index < n) {
                result += s[index];
                if (row != 0 && row != numRows - 1) {
                    size_t offset = chars_per_section - 2 * row;
                    if (offset + index < n) {
                        result += s[offset + index];
                    }
                }
                index += chars_per_section;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end

// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end

// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

 */
