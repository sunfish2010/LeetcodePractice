/*
 * @lc app=leetcode id=973 lang=cpp
 * @lcpr version=21913
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const auto dist_to_origin = [](const vector<int>& point) {
            return sqrt(point[0] * point[0] + point[1] * point[1]);
        };
        const auto cmp = [&dist_to_origin](const vector<int>& point_a, const vector<int>& point_b) {
            return dist_to_origin(point_a) < dist_to_origin(point_b);
        };
        priority_queue k_closest(points.begin(), points.begin() + k, cmp);
        for (int i = k; i < points.size(); ++i) {
            if (dist_to_origin(points[i]) < dist_to_origin(k_closest.top())) {
                k_closest.pop();
                k_closest.push(points[i]);
            }
        }
        vector<vector<int>> results;
        while (!k_closest.empty()) {
            results.push_back(std::move(k_closest.top()));
            k_closest.pop();
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[-2,2]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,3],[5,-1],[-2,4]]\n2\n
// @lcpr case=end

 */
