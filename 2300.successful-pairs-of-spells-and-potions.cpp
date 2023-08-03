/*
 * @lc app=leetcode id=2300 lang=cpp
 * @lcpr version=21912
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> results;
        for (const auto& spell : spells) {
            int target = ceil(success / static_cast<double>(spell));
            const auto first = lower_bound(potions.begin(), potions.end(), target);
            results.push_back(std::distance(first, potions.end()));
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,1,3]\n[1,2,3,4,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n[8,5,8]\n16\n
// @lcpr case=end

 */
