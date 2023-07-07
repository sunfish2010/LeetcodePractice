/*
 * @lc app=leetcode id=134 lang=cpp
 * @lcpr version=21909
 *
 * [134] Gas Station
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Can only start at position with net cost >= 0 and total sum needs to be greater than 0;
        int sum = 0;
        int index = -1;
        int circular_sum = 0;
        for (int i = 0; i < cost.size(); ++i) {
            cost[i] = gas[i] - cost[i];
            sum += cost[i];
            circular_sum += cost[i];
            if (circular_sum < 0) {
                circular_sum = 0;
                index = i + 1;
            }
        }
        if (sum < 0) {
            return -1;
        }
        return index;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n[3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end

 */
