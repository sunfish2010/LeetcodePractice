/*
 * @lc app=leetcode id=155 lang=cpp
 * @lcpr version=21913
 *
 * [155] Min Stack
 */

// @lc code=start
#include <stack>
using namespace std;

class MinStack {
   public:
    MinStack() {
    }

    void push(int val) {
        min_stack_.push(val);
        if (min_vals.empty() || val < min_vals.top().first) {
            min_vals.push({val, 1});
        } else if (val == min_vals.top().first) {
            min_vals.top().second++;
        }
    }

    void pop() {
        if (min_stack_.top() == min_vals.top().first) {
            min_vals.top().second--;
            if (min_vals.top().second == 0) {
                min_vals.pop();
            }
        }
        min_stack_.pop();
    }

    int top() {
        return min_stack_.top();
    }

    int getMin() {
        return min_vals.top().first;
    }

   private:
    stack<int> min_stack_;
    stack<pair<int, int>> min_vals;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
