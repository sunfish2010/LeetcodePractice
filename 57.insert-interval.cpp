/*
 * @lc app=leetcode id=57 lang=cpp
 * @lcpr version=21913
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }
        int index = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        intervals.insert(intervals.begin() + index, newInterval);

        return merge_intervals(intervals);
    }

   private:
    vector<vector<int>> merge_intervals(vector<vector<int>>& intervals) {
        int curr = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            // no overlap.
            if (intervals[curr].back() < intervals[i].front()) {
                intervals[++curr] = intervals[i];
            } else {
                intervals[curr].back() = max(intervals[i].back(), intervals[curr].back());
            }
        }
        int num_overlap = intervals.size()-1 - curr;
        while (num_overlap > 0) {
            intervals.pop_back();
            num_overlap--;
        }
        return intervals;
    }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[6,9]]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8]\n
// @lcpr case=end

 */
