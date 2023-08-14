/*
 * @lc app=leetcode id=525 lang=cpp
 * @lcpr version=21913
 *
 * [525] Contiguous Array
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> count_map;
        int max_length = 0;
        int count = 0;
        count_map[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i] == 1 ? 1 : -1;
            // When count is the same, that means from index i to j the total sum is 0, which means there is equal number of 0 and 1.
            if (count_map.find(count) != count_map.end()) {
                max_length = max(max_length, i - count_map[count]);
            } else {
                count_map[count] = i;
            }
        }
        return max_length;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0]\n
// @lcpr case=end

 */
