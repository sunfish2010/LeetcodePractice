/*
 * @lc app=leetcode id=739 lang=cpp
 * @lcpr version=21913
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size(), 0);
        int highest_temp = temperatures.back();
        for (int i = temperatures.size() - 2; i >= 0; --i) {
            // If the temperature is already the highest, it can't be higher.
            if (temperatures[i] >= highest_temp) {
                highest_temp = temperatures[i];
            } else {
                // Lookup the results stored to find first temp higher.
                int day = 1;
                while (temperatures[i] >= temperatures[i + day]) {
                    day += results[i + day];
                }
                results[i] = day;
            }
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [73,74,75,71,69,72,76,73]\n
// @lcpr case=end

// @lcpr case=start
// [30,40,50,60]\n
// @lcpr case=end

// @lcpr case=start
// [30,60,90]\n
// @lcpr case=end

 */
