/*
 * @lc app=leetcode id=80 lang=cpp
 * @lcpr version=21913
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int read = 0;
        int write = 0;
        int prev = nums[0];
        int count = 0;
        while (read < nums.size()) {
            if (nums[read] == prev) {
                count++;
            } else {
                count = 1;
            }
            if (count < 3) {
                nums[write++] = nums[read];
            }
            prev = nums[read];
            read++;
        }
        return write;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */
