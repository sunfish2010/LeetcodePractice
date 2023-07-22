/*
 * @lc app=leetcode id=162 lang=cpp
 * @lcpr version=21909
 *
 * [162] Find Peak Element
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    // Because it only needs to find one solution, we can return any result by using binary search.
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return (left + right - left) / 2;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,3,5,6,4]\n
// @lcpr case=end

 */
