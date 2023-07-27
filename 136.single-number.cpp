/*
 * @lc app=leetcode id=136 lang=cpp
 * @lcpr version=21912
 *
 * [136] Single Number
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (const auto& n : nums) {
            num ^ n;
        }
        return num;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
