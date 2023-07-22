/*
 * @lc app=leetcode id=560 lang=cpp
 * @lcpr version=21909
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int curr_sum = 0;
        unordered_map<int, int> sum_map({0, 1});
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curr_sum += nums[i];
            count += sum_map[curr_sum - k];
            sum_map[curr_sum]++;
        }
        return count;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */
