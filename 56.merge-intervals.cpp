/*
 * @lc app=leetcode id=56 lang=cpp
 * @lcpr version=21912
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& interval_a, const vector<int>& interval_b) {
            if (interval_a[0] == interval_b[0]) {
                return interval_a[1] < interval_b[1];
            }
            return interval_a[0] < interval_b[0];
        });
        int curr = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            // no overlap.
            if (intervals[curr].back() < intervals[i].front()) {
                intervals[++curr] = intervals[i];
            } else {
                intervals[curr].back() = max(intervals[i].back(), intervals[curr].back());
            }
        }
        int num_overlap = intervals.size() - 1 - curr;
        while (num_overlap > 0) {
            intervals.pop_back();
            num_overlap--;
        }
        return intervals;
    }
};
/*

from typing import List

# Definition for singly-linked list.
def merge(self, intervals: List[List[int]]) -> List[List[int]]:
    intervals.sort(key=lambda interval:interval[0])
    curr = 0
    for i in range(1, len(intervals)):
        #  no overlap.
        if intervals[curr][1] < intervals[i][0]:
            curr += 1
            intervals[curr] = intervals[i]
        else:
            intervals[curr][1] = max(intervals[curr][1], intervals[i][1])

    return  intervals[:curr+1]

*/
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */
