/*
 * @lc app=leetcode id=17 lang=cpp
 * @lcpr version=21912
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if (digits.empty()) {
            return {};
        }
        string curr_str;
        generate_string(curr_str, 0, digits);
        return results;
    }

   private:
    void generate_string(string& curr_str, int i, const string& digits) const {
        if (curr_str.size() == n) {
            results.push_back(curr_str);
            return;
        }
        for (const char& c : maps[digits[i] - '2']) {
            curr_str += c;
            generate_string(curr_str, i + 1, digits);
            curr_str.pop_back();
        }
    }
    mutable vector<string> results;
    int n = 0;
    vector<string> maps = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
// @lc code=end

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */
