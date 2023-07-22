/*
 * @lc app=leetcode id=75 lang=cpp
 * @lcpr version=21909
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int red_idx = 0;
        int white_idx = 0;
        int blue_idx = nums.size() - 1;
        while (white_idx <= blue_idx) {
            if (nums[white_idx] == 1) {
                // Already in place.
                white_idx++;
            } else if (nums[white_idx] == 0) {
                if (nums[red_idx] != 0) {
                    swap(nums[red_idx], nums[white_idx]);
                }
                red_idx++;
                white_idx++;
            } else {
                if (nums[blue_idx] != 2) {
                    swap(nums[white_idx], nums[blue_idx]);
                }
                blue_idx--;
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */
