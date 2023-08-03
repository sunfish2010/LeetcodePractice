/*
 * @lc app=leetcode id=198 lang=cpp
 * @lcpr version=21912
 *
 * [198] House Robber
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
        }
        return nums.back();
    }
};

/*

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        nums[1] = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            nums[i] = max(nums[i] + nums[i-2], nums[i-1])
        return nums[-1]

*/
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */
