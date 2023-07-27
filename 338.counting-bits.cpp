/*
 * @lc app=leetcode id=338 lang=cpp
 * @lcpr version=21912
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> results(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // x / 2 is x >> 1 and x % 2 is x & 1
            results[i] = results[i >> 1] + (i & 1);
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */
