/*
 * @lc app=leetcode id=2390 lang=cpp
 * @lcpr version=21909
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
#include <string>
using namespace std;

// O(n) time and O(1) space.
class Solution {
   public:
    string removeStars(string s) {
        int write = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                if (write == -1) {
                    write = i - 1;
                } else {
                    write--;
                }
            } else {
                if (write != -1) {
                    s[write] = s[i];
                    write++;
                }
            }
        }
        if (write >= 0 && write < s.size()) {
            s.erase(s.begin() + write, s.end());
        }
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "leet**cod*e"\n
// @lcpr case=end

// @lcpr case=start
// "erase*****"\n
// @lcpr case=end

 */
