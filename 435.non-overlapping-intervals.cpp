/*
 * @lc app=leetcode id=435 lang=cpp
 * @lcpr version=21909
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& interval_a, const vector<int>& interval_b) {
            if (interval_a[0] == interval_b[0]) {
                return interval_a[1] < interval_b[1];
            }
            return interval_a[0] < interval_b[0];
        });
        // We only need to keep track of the end since everything is already sorted.
        int end = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            // no overlap, update start and end.
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            } else {
                ++count;
                end = std::min(intervals[i][1], end);
            }
        }
        return count;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [[1,2],[2,3],[3,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[1,2],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3]]\n
// @lcpr case=end

 */
