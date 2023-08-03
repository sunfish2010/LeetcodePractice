/*
 * @lc app=leetcode id=169 lang=cpp
 * @lcpr version=21912
 *
 * [169] Majority Element
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            count += nums[i] == num ?: 1 - 1;
            if (count == 0) {
                num = nums[i];
                count = 1;
            }
        }
        return num;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */
