/*
 * @lc app=leetcode id=228 lang=cpp
 * @lcpr version=21913
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int start = nums[0];
        int curr = start;
        vector<string> results;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == curr + 1) {
                curr = nums[i];
                continue;
            }
            int end = nums[i - 1];
            if (end - start == 0) {
                results.push_back(to_string(start));
            } else {
                results.push_back(to_string(start) + "->" + to_string(end));
            }
            start = nums[i];
            curr = start;
        }
        if (nums.back() - start > 0) {
            results.push_back(to_string(start) + "->" + to_string(nums.back()));
        } else {
            results.push_back(to_string(nums.back()));
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,2,4,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,3,4,6,8,9]\n
// @lcpr case=end

 */
