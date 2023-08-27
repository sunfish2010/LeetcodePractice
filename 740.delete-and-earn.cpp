/*
 * @lc app=leetcode id=740 lang=cpp
 * @lcpr version=21913
 *
 * [740] Delete and Earn
 */

// @lc code=start
#include <map>
#include <vector>
using namespace std;
class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> points;
        for (const auto& num : nums) {
            points[num] += num;
        }
        int two_back = 0;
        int one_back = points[0];
        auto iter = std::next(points.begin());
        while (iter != points.end()) {
            int curr;
            if (iter->first == std::prev(iter)->first + 1) {
                curr = max(two_back + iter->second, one_back);
            } else {
                curr = max(two_back + iter->second, one_back + iter->second);
            }
            two_back = one_back;
            one_back = curr;
            ++iter;
        }
        return one_back;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,3,3,3,4]\n
// @lcpr case=end

 */
