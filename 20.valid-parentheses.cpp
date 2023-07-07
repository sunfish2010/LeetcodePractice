/*
 * @lc app=leetcode id=20 lang=cpp
 * @lcpr version=21909
 *
 * [20] Valid Parentheses
 */
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        stack<char> parentheses;
        if (s.size() % 2 != 0) {
            return false;
        }

        for (const char& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                parentheses.push(c);
            } else {
                if (parentheses.empty()) {
                    return false;
                }
                char top_char = parentheses.top();
                if (top_char != lookup_table[c]) {
                    return false;
                }
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }

   private:
    std::unordered_map<char, char> lookup_table{{'}', '{'}, {')', '('}, {']', '['}};
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */
