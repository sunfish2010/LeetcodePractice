/*
 * @lc app=leetcode id=121 lang=cpp
 * @lcpr version=21912
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <climits>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min_price = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            min_price = min(min_price, prices[i]);
            profit = max(profit, prices[i] - min_price);
        }
        return profit;
    }
};

/*

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        min_price = prices[0]
        for i in range(1, len(prices)):
            min_price = min(min_price, prices[i])
            profit = max(profit, prices[i] - min_price)
        return profit

*/
// @lc code=end

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
