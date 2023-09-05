/*
 * @lc app=leetcode id=901 lang=cpp
 * @lcpr version=21913
 *
 * [901] Online Stock Span
 */

// @lc code=start
#include <stack>
#include <utility>
using namespace std;
class StockSpanner {
   public:
    StockSpanner() {
        previous_prices = stack<pair<int, int>>();
    }

    int next(int price) {
        int num = 1;
        while (!previous_prices.empty() && (previous_prices.top().first <= price)) {
            num += previous_prices.top().second;
            previous_prices.pop();
        }
        previous_prices.push({price, num});
        return num;
    }

   private:
    stack<pair<int, int>> previous_prices;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
