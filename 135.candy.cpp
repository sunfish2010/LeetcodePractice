/*
 * @lc app=leetcode id=135 lang=cpp
 * @lcpr version=21912
 *
 * [135] Candy
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int candy(vector<int>& ratings) {
        // The base line is always 1, when we see an increase/decrease, the candies need to be +1 as adjustments.
        int candies = 0;
        int up = 0;
        int down = 0;
        int prev_k = 0;
        const auto total_num = [](int n) {
            return n * (n + 1) / 2;
        };
        for (int i = 1; i < ratings.size(); ++i) {
            int k = ratings[i] > ratings[i - 1] ? 1 : ratings[i] == ratings[i - 1] ? 0
                                                                                   : -1;
            // Can set a 1 to local minimum
            if (prev_k < 0 && k > 0 || k == 0) {
                // max(up, down) is the base ones we didn't count for because ups and downs are only additional candies to ones.
                // for example,  1 3 5 4, we have 2 ups and 1 down, that's three numbers,
                candies += total_num(up) + total_num(down) + max(up, down);
                up = 0;
                down = 0;
            }
            if (k > 0) {
                up++;
            } else if (k < 0) {
                down++;
            } else {
                candies++;
            }
            prev_k = k;
        }
        // 1 is the first candy.
        candies += total_num(up) + total_num(down) + max(up, down) + 1;
        return candies;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */
