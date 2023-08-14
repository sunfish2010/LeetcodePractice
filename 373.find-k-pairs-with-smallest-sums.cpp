/*
 * @lc app=leetcode id=373 lang=cpp
 * @lcpr version=21913
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const auto cmp = [](const vector<int>& pair_a, const vector<int>& pair_b) {
            return pair_a[0] + pair_a[1] < pair_b[0] + pair_b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> k_smallest;
        for (size_t i = 0; i < nums1.size(); ++i) {
            for (size_t j = 0; j < nums2.size(); ++j) {
                const auto curr_pair = {nums1[i], nums2[j]};
                if (k_smallest.size() < k) {
                    k_smallest.push(curr_pair);
                    continue;
                }
                if (cmp(curr_pair, k_smallest.top())) {
                    k_smallest.pop();
                    k_smallest.push(curr_pair);
                } else {
                    // only going to get larger.
                    break;
                }
            }
        }
        vector<vector<int>> results;
        while (!k_smallest.empty()) {
            results.push_back(move(k_smallest.top()));
            k_smallest.pop();
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3]\n3\n
// @lcpr case=end

 */
