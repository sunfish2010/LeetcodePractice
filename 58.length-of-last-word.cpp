/*
 * @lc app=leetcode id=58 lang=cpp
 * @lcpr version=21909
 *
 * [58] Length of Last Word
 */

// @lc code=start

#include <string>
using namespace std;

class Solution {
   public:
    int lengthOfLastWord(string s) {
        bool has_seen_world = false;
        int num_char = s.size();
        int length = 0;
        for (int i = num_char - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (!has_seen_world) {
                    continue;
                } else {
                    return length;
                }
            } else {
                length++;
                has_seen_world = true;
            }
        }
        return length;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */
