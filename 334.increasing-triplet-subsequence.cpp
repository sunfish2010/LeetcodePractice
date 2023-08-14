/*
 * @lc app=leetcode id=334 lang=cpp
 * @lcpr version=21913
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int min_num = INT_MAX;
        int mid_num = min_num;
        for (size_t i = 0; i < nums.size(); ++i) {
            // Important to put = since the sequence needs be strictly increasing.
            // not putting the = leaves non strictly increasing sequence in the last else.
            if (nums[i] <= min_num) {
                min_num = nums[i];
            } else if (nums[i] <= mid_num) {
                mid_num = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,5,0,4,6]\n
// @lcpr case=end

 */
