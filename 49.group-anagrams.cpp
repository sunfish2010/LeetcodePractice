/*
 * @lc app=leetcode id=49 lang=cpp
 * @lcpr version=21913
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const auto sort_string = [](const string& input) {
            string sorted = input;
            sort(sorted.begin(), sorted.end());
            return sorted;
        };
        unordered_map<string, std::vector<string>> groups;
        for (const auto& str : strs) {
            groups[sort_string(str)].push_back(str);
        }
        vector<vector<string>> results;
        for (auto& [key, val] : groups) {
            results.push_back(move(val));
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["eat","tea","tan","ate","nat","bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */
