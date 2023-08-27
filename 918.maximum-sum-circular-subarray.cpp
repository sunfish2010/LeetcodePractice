/*
 * @lc app=leetcode id=918 lang=cpp
 * @lcpr version=21913
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_max = 0;
        int max_sum = INT_MIN;
        int total_sum = 0;
        int curr_min = 0;
        int min_sum = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            curr_max = max(curr_max + nums[i], nums[i]);
            curr_min = min(curr_min + nums[i], nums[i]);
            max_sum = max(max_sum, curr_max);
            min_sum = min(min_sum, curr_min);
            total_sum += nums[i];
        }
        return total_sum == min_sum ? max_sum : max(max_sum, total_sum - min_sum);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,-2,3,-2]\n
// @lcpr case=end

// @lcpr case=start
// [5,-3,5]\n
// @lcpr case=end

// @lcpr case=start
// [-3,-2,-3]\n
// @lcpr case=end

 */
