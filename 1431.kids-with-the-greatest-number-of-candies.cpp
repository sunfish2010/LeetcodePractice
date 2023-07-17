/*
 * @lc app=leetcode id=1431 lang=cpp
 * @lcpr version=21909
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies = *max_element(candies.begin(), candies.end());
        vector<bool> can_be_greatest(candies.size(), false);
        for (size_t i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= max_candies) {
                can_be_greatest[i] = true;
            }
        }
        return can_be_greatest;
    };
}
// @lc code=end

/*
// @lcpr case=start
// [2,3,5,1,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4,2,1,1,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [12,1,12]\n10\n
// @lcpr case=end

 */
