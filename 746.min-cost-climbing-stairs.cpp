/*
 * @lc app=leetcode id=746 lang=cpp
 * @lcpr version=21912
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        // sum[i] = min(sum[i-1] + cost[i], sum[i-2] + cost[i])
        int num_stairs = cost.size();
        for (int i = 2; i < num_stairs; ++i) {
            cost[i] = min(cost[i - 1] + cost[i], cost[i - 2] + cost[i]);
        }
        return min(cost[num_stairs - 1], cost[num_stairs - 2]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,15,20]\n
// @lcpr case=end

// @lcpr case=start
// [1,100,1,1,1,100,1,1,100,1]\n
// @lcpr case=end

 */
