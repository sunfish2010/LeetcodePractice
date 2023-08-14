/*
 * @lc app=leetcode id=31 lang=cpp
 * @lcpr version=21913
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 1 && nums[i] > nums[i + 1]) {
            i--;
        }
        if (i > 0) {
            int j = nums.size() - 1;
            // The latter part is sorted, find first element larger to exchange to find the next permutation.
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        // Now the latter part still sorted in decreasing order from left to right. reverse
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,5]\n
// @lcpr case=end

 */
