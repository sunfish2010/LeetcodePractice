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
/*
class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(k >= points.size()){
            return points;
        }
        int left = 0;
        int right = points.size() -1;
        int pivot = right + 1;
        while(pivot !=k){
            pivot = partition(points, left, right);
            if(pivot < k){
                left = pivot + 1;
            }else if (pivot > k){
                right = pivot -1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
        
    }

    private:
    int partition(vector<vector<int>>& points, int left, int right){
        static const auto dist_to_origin = [](const vector<int>& point) {
            return point[0] * point[0] + point[1] * point[1];
        };
        int pivot_dist = dist_to_origin(points[right]);
        int i = left;
        for(int j = left; j < right;++j){
            if(dist_to_origin(points[j]) <= pivot_dist){
                swap(points[i++], points[j]);
            }
        }
        swap(points[i], points[right]);
        return i;
    }
};

*/
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[-2,2]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,3],[5,-1],[-2,4]]\n2\n
// @lcpr case=end

 */
