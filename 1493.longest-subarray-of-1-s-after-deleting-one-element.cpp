/*
 * @lc app=leetcode id=1493 lang=cpp
 * @lcpr version=21912
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int longestSubarray(vector<int>& nums) {
        int max_length = 0;
        int curr_length = 0;
        int i = 0;
        bool has_zero = false;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                int end = -1;
                int length_following_subarray = longest_subarray(nums, i + 1, end);
                max_length = max(max_length, curr_length + length_following_subarray);
                curr_length = length_following_subarray;
                i = end;
                has_zero = true;
            } else {
                curr_length++;
                ++i;
            }
        }
        max_length = max(curr_length, max_length);
        return has_zero ? max_length : max_length - 1;
    }

   private:
    int longest_subarray(const vector<int>& nums, int start, int& end) {
        int length = 0;
        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] != 1) {
                end = i;
                return length;
            }
            length++;
        }
        return length;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,0,1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */
