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
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
