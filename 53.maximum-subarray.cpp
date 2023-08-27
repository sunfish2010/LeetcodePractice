/*
 * @lc app=leetcode id=53 lang=cpp
 * @lcpr version=21913
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            curr_sum = max(curr_sum + nums[i], nums[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
