/*
 * @lc app=leetcode id=238 lang=cpp
 * @lcpr version=21912
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int num_zero = 0;
        for (const auto& num : nums) {
            if (num == 0) {
                num_zero++;
            } else {
                product *= num;
            }
        }
        if (num_zero > 1) {
            return vector<int>(nums.size(), 0);
        }
        vector<int> results(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (num_zero) {
                results[i] = nums[i] == 0 ? product : 0;
            } else {
                results[i] = product / nums[i];
            }
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */
