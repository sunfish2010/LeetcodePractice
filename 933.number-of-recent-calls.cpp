/*
 * @lc app=leetcode id=933 lang=cpp
 * @lcpr version=21909
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
#include <queue>
using namespace std;

class RecentCounter {
   public:
    RecentCounter() {
        while (!ping_records.empty()) {
            ping_records.pop();
        }
    }

    int ping(int t) {
        ping_records.push(t);
        while (t - ping_records.front() > 3000) {
            ping_records.pop();
        }
        return ping_records.size();
    }

   private:
    queue<int> ping_records;
};

/**
 *  Python 3
from collections import deque

class RecentCounter:

    def __init__(self):
        self.window = deque()

    def ping(self, t: int) -> int:
        self.window.append(t)
        while t - self.window[0] > 3000:
            self.window.popleft()
        return len(self.window)

 */
// @lc code=end
