/*
 * @lc app=leetcode id=39 lang=cpp
 * @lcpr version=21913
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        while (!candidates.empty() && candidates.back() > target) {
            candidates.pop_back();
        }
        if (candidates.empty()) {
            return {};
        }
        target_ = target;
        vector<int> curr_combo;
        generate_combination(candidates, curr_combo, 0);
        return combinations_;
    }

   private:
    bool generate_combination(const vector<int>& candidates, vector<int>& curr, int index) {
        if (curr_sum_ == target_) {
            combinations_.push_back(curr);
            return false;
        }
        if (curr_sum_ > target_) {
            return false;
        }
        for (int i = index; i < candidates.size(); ++i) {
            curr_sum_ += candidates[i];
            curr.push_back(candidates[i]);
            const bool to_continue = generate_combination(candidates, curr, i);
            curr.pop_back();
            curr_sum_ -= candidates[i];
            if (!to_continue) {
                break;
            }
        }
        return true;
    }

    int curr_sum_ = 0;
    int target_;
    vector<vector<int>> combinations_;
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
