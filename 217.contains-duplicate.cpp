/*
 * @lc app=leetcode id=217 lang=cpp
 * @lcpr version=21912
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        unordered_set<int>nums_deduplicated(nums.begin(), nums.end());
        return nums_deduplicated.size() < nums.size();
        */
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

/*
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)
*/

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,3,3,4,3,2,4,2]\n
// @lcpr case=end

 */
