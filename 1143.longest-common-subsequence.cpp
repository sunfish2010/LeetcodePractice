/*
 * @lc app=leetcode id=1143 lang=cpp
 * @lcpr version=21913
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> length(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    length[i][j] = 1 + length[i + 1][j + 1];
                } else {
                    length[i][j] = max(length[i + 1][j], length[i][j + 1]);
                }
            }
        }
        return length[0][0];
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */
