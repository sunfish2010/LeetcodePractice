/*
 * @lc app=leetcode id=179 lang=cpp
 * @lcpr version=21913
 *
 * [179] Largest Number
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        vector<string> num_strs;
        num_strs.reserve(nums.size());
        for (auto& num : nums) {
            num_strs.push_back(to_string(num));
        }
        const auto cmp = [](const string& a, const string& b) {
            return a + b > b + a;
        };
        sort(num_strs.begin(), num_strs.end(), cmp);
        string result;
        for (auto str : num_strs) {
            result += move(str);
        }
        if (result[0] == '0') {
            return "0";
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,30,34,5,9]\n
// @lcpr case=end

 */
