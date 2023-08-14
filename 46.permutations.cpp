/*
 * @lc app=leetcode id=46 lang=cpp
 * @lcpr version=21913
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
    }

   private:
    void back_tracking(const vector<int>& nums, vector<int>& curr) {
        if (curr.size() == nums.size()) {
            permutations.push_back(curr);
            return;
        }
        for (const auto& num : nums) {
            if (find(curr.begin(), curr.end(), num) == curr.end()) {
                curr.push_back(num);
            }
        }
    }

    vector<vector<int>> permutations;
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
