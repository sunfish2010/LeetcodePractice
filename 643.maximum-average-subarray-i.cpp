/*
 * @lc app=leetcode id=643 lang=cpp
 * @lcpr version=21909
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int i = 0;
        while (i < k) {
            sum += nums[i];
            ++i;
        }
        int max_sum = sum;

        while (i < nums.size()) {
            sum += nums[i];
            sum -= nums[i - k];
            max_sum = max(sum, max_sum);
        }
        return static_cast<double>(max_sum) / k;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,12,-5,-6,50,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n
// @lcpr case=end

 */
