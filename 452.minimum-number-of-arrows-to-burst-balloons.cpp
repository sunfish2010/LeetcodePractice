/*
 * @lc app=leetcode id=452 lang=cpp
 * @lcpr version=21913
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& point_a, const vector<int>& point_b) {
            return point_a[1] < point_b[1];
        });
        int prev_end = points[0][1];
        int num_arrows = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > prev_end) {
                num_arrows++;
                prev_end = points[i][1];
            }
        }
        return num_arrows;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[10,16],[2,8],[1,6],[7,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4],[5,6],[7,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5]]\n
// @lcpr case=end

 */
