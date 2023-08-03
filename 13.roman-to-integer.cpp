/*
 * @lc app=leetcode id=13 lang=cpp
 * @lcpr version=21912
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int romanToInt(string s) {
        static unordered_map<char, int> lookup = {{'I', 1},
                                                  {'V', 5},
                                                  {'X', 10},
                                                  {'L', 50},
                                                  {'C', 100},
                                                  {'D', 500},
                                                  {'M', 1000}};
        int num = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (lookup[s[i]] < lookup[s[i + 1]]) {
                num -= lookup[s[i]];
            } else {
                num += lookup[s[i]];
            }
        }
        num += lookup[s.back()];
    }
};

/*

class Solution:
    def romanToInt(self, s: str) -> int:
        lookup = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        num = 0
        for i in range(len(s) -1):
            if s[i] in lookup and s[i+1] in lookup:
                if lookup[s[i]] < lookup[s[i+1]]:
                    num -= lookup[s[i]]
                else:
                    num += lookup[s[i]]
        num += lookup[s[-1]]
        return num
*/
// @lc code=end

/*
// @lcpr case=start
// "III"\n
// @lcpr case=end

// @lcpr case=start
// "LVIII"\n
// @lcpr case=end

// @lcpr case=start
// "MCMXCIV"\n
// @lcpr case=end

 */
