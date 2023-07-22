/*
 * @lc app=leetcode id=724 lang=cpp
 * @lcpr version=21909
 *
 * [724] Find Pivot Index
 */

// @lc code=start
#include <numeric>
#include <vector>

using namespace std;

class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int left_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left_sum = sum - left_sum - nums[i]) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,7,3,6,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,-1]\n
// @lcpr case=end

 */
