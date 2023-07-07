/*
 * @lc app=leetcode id=151 lang=cpp
 * @lcpr version=21909
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        string reversed_string;
        stack<char> word;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                // No word yet.
                if (word.empty()) {
                    continue;
                } else {
                    if (!reversed_string.empty()) {
                        reversed_string += ' ';
                    }
                    while (!word.empty()) {
                        reversed_string += word.top();
                        word.pop();
                    }
                }
            } else {
                word.push(s[i]);
            }
        }
        // Add the last word in if ends with a word.
        if (!word.empty()) {
            if (!reversed_string.empty()) {
                reversed_string += ' ';
            }
            while (!word.empty()) {
                reversed_string += word.top();
                word.pop();
            }
        }

        return reversed_string;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello word  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */
