/*
 * @lc app=leetcode id=215 lang=cpp
 * @lcpr version=21909
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        // Smallest element at the top.
        // std::priority_queue<int, std::vector<int>, std::greater<int>>
        priority_queue data(nums.begin(), nums.begin() + k, std::greater<int>());
        for (int i = k; i < nums.size(); ++i) {
            data.push(nums[i]);
            if (data.size() > k) {
                data.pop();
            }
        }
        return data.top();
    }

    // TODO: (quick select version)
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,1,5,6,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,1,2,4,5,5,6]\n4\n
// @lcpr case=end

 */
