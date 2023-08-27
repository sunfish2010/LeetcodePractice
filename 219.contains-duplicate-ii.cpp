/*
 * @lc app=leetcode id=219 lang=cpp
 * @lcpr version=21913
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> prevs;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (prevs.find(nums[i]) != prevs.end()) {
                return true;
            }
            prevs.insert(nums[i]);
            if (prevs.size() > k) {
                prevs.erase(nums[i - k]);
            }
        }
        return false;
    }
};

/*

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        prevs = set()
        for i in range(len(nums)):
            if nums[i] in prevs:
                return True
            prevs.add(nums[i])
            if len(prevs) > k:
                prevs.remove(nums[i-k])
        return False

*/
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */
