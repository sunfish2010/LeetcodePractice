/*
 * @lc app=leetcode id=714 lang=cpp
 * @lcpr version=21913
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // cost to buy stock.
        int cost = -prices[0];
        int no_stock = 0;
        for (int i = 1; i < n; ++i) {
            // sell
            int tmp = no_stock;
            no_stock = max(no_stock, cost + prices[i] - fee);
            cost = max(cost, tmp - prices[i]);
        }
        return no_stock;

        /*
        Come from optimization of the following dp
         int n = prices.size();
        vector<int> free(n, 0), hold(n, 0);

        // In order to hold a stock on day 0, we have no other choice but to buy it for prices[0].
        hold[0] = -prices[0];

        for (int i = 1; i < n; i++) {
            free[i] = max(free[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], free[i - 1] - prices[i]);
        }

        return free[n - 1];

        */
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,2,8,4,9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,7,5,10,3]\n3\n
// @lcpr case=end

 */
