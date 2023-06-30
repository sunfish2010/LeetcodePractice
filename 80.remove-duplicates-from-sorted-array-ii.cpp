/*
 * @lc app=leetcode id=80 lang=cpp
 * @lcpr version=21909
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int num_occurances = 1;
        int insert_idx = -1;
        int num_duplicates = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                num_occurances++;
                // The number has occurred for more than twice.
                if (num_occurances > 2) {
                    num_duplicates++;
                    // Mark the insertion idx for the first duplicate number.
                    if (insert_idx == -1) {
                        insert_idx = i;
                    }
                } else if (insert_idx != -1) {
                    nums[insert_idx] = nums[i];
                    insert_idx++;
                }
            } else {
                num_occurances = 1;
                if (insert_idx != -1) {
                    nums[insert_idx] = nums[i];
                    insert_idx++;
                }
            }
        }
        return nums.size() - num_duplicates;
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
