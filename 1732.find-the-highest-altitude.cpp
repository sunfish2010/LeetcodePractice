/*
 * @lc app=leetcode id=1732 lang=cpp
 * @lcpr version=21909
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int largestAltitude(vector<int>& gain) {
        int height = 0;
        int max_height = 0;
        for (const auto& g : gain) {
            height += g;
            max_height = std::max(height, max_height);
        }
        return max_height;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-5,1,5,0,-7]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-3,-2,-1,4,3,2]\n
// @lcpr case=end

 */
