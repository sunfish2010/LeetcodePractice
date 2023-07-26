/*
 * @lc app=leetcode id=1313 lang=cpp
 * @lcpr version=21912
 *
 * [1313] Decompress Run-Length Encoded List
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> results;
        results.reserve(nums.size() / 2);
        for (int i = 0; i < nums.size() / 2; ++i) {
            int freq = nums[2 * i];
            int num = nums[2 * i + 1];
            for (int j = 0; j < freq; ++j) {
                results.push_back(num);
            }
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3]\n
// @lcpr case=end

 */
