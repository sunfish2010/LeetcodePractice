/*
 * @lc app=leetcode id=1004 lang=cpp
 * @lcpr version=21912
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        for (right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                k--;
            }
            if (k < 0) {
                // This may not be a valid solution but it keeps the window size constant.
                k += 1 - nums[left];
                left++;
            }
        }
        return right - left;
    }
};

/*
from typing import List

def longestOnes(self, nums: List[int], k: int) -> int:
    left = 0
    right = 0
    while right < len(nums):
        if nums[right] == 0:
            k -= 1
        if k < 0:
            # return one possible flips if left is 0.
            k += 1 - nums[left]
            left += 1
        right += 1
    return right - left

*/
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,0,0,0,1,1,1,1,0]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3\n
// @lcpr case=end

 */
