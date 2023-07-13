/*
 * @lc app=leetcode id=283 lang=cpp
 * @lcpr version=21909
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int read = 0;
        int write = -1;
        while (read < nums.size()) {
            if (nums[read] != 0 && write != -1) {
                nums[write] = nums[read];
                write++;
            } else if (nums[read] == 0 && write == -1) {
                write = read;
            }
            read++;
        }
        for (int i = write; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
