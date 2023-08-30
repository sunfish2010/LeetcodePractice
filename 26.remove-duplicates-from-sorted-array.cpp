/*
 * @lc app=leetcode id=26 lang=cpp
 * @lcpr version=21913
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int read = 1;
        int write = 1;
        while (read < nums.size()) {
            if (nums[read] == nums[read - 1]) {
                read++;
            } else {
                nums[write++] = nums[read++];
            }
        }
        return write;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */
