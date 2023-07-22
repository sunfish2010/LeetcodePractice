/*
 * @lc app=leetcode id=394 lang=cpp
 * @lcpr version=21912
 *
 * [394] Decode String
 */

// @lc code=start
#include <cctype>
#include <stack>
#include <string>
using namespace std;

class Solution {
   public:
    string decodeString(string s) {
        stack<int> repeat_times;
        stack<string> substrings;
        string curr_str;
        int k = 0;
        for (const auto& c : s) {
            if (isdigit(static_cast<unsigned char>(c))) {
                k = k * 10 + c - '0';
            } else if (c == '[') {
                substrings.push(curr_str);
                repeat_times.push(k);
                k = 0;
                curr_str = "";
            } else if (c == ']') {
                int repeat = repeat_times.top();
                repeat_times.pop();
                string decoded_string = substrings.top();
                substrings.pop();
                while (repeat > 0) {
                    decoded_string += curr_str;
                    repeat--;
                }
                curr_str = decoded_string;
            } else {
                curr_str += c;
            }
        }
        return curr_str;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "3[a]2[bc]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

 */
