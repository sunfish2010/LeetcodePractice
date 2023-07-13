/*
 * @lc app=leetcode id=1768 lang=cpp
 * @lcpr version=21909
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        if (word1.empty()) {
            return word2;
        }
        if (word2.empty()) {
            return word1;
        }
        int idx_1 = 0;
        int idx_2 = 0;
        string result;
        bool odd = true;
        while (idx_1 < word1.size() && idx_2 < word2.size()) {
            if (odd) {
                result += word1[idx_1];
                idx_1++;
            } else {
                result += word2[idx_2];
                idx_2++;
            }
            odd = !odd;
        }
        while (idx_1 < word1.size()) {
            result += word1[idx_1++];
        }
        while (idx_2 < word2.size()) {
            result += word2[idx_2++];
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"pqr"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"pqrs"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"pq"\n
// @lcpr case=end

 */
