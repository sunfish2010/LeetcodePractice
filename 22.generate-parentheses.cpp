/*
 * @lc app=leetcode id=22 lang=cpp
 * @lcpr version=21913
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        n_ = n;
        generate_parenthesis(0, 0);
        return results;
    }

   private:
    void generate_parenthesis(int num_left, int num_right) {
        if (num_left + num_right > n_) {
            return;
        }
        if (num_left == num_right && curr.size() == 2 * n_) {
            results.push_back(curr);
            return;
        }
        if (num_left < n_) {
            curr += '(';
            generate_parenthesis(num_left + 1, num_right);
            curr.pop_back();
        }
        if (num_right < num_left) {
            curr += ')';
            generate_parenthesis(num_left, num_right + 1);
            curr.pop_back();
        }
    }
    string curr = "";
    vector<string> results;
    int n_;
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
