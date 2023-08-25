/*
 * @lc app=leetcode id=290 lang=cpp
 * @lcpr version=21913
 *
 * [290] Word Pattern
 */

// @lc code=start
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        vector<string> words = unparse_string(s);
        unordered_map<char, int> patterns;
        unordered_map<string, int> string_patterns;
        if (pattern.size() != words.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); ++i) {
            const auto p = pattern[i];
            if (patterns.count(p) == 0) {
                patterns[p] = i;
            }
            if (string_patterns.count(words[i]) == 0) {
                string_patterns[words[i]] = i;
            }
            if (patterns[p] != string_patterns[words[i]]) {
                return false;
            }
        }
        return true;
    }

   private:
    vector<string> unparse_string(string s) {
        string curr;
        vector<string> results;
        stringstream ss(s);

        while (getline(ss, curr, ' ')) {
            results.push_back(curr);
        }

        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abba"\n"dog cat cat dog"\n
// @lcpr case=end

// @lcpr case=start
// "abba"\n"dog cat cat fish"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"dog cat cat dog"\n
// @lcpr case=end

 */
