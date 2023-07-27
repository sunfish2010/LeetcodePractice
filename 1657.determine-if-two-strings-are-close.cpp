/*
 * @lc app=leetcode id=1657 lang=cpp
 * @lcpr version=21912
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        auto freq1 = obtain_signature(word1);
        auto freq2 = obtain_signature(word2);
        for (int i = 0; i < freq1.size(); ++i) {
            if (freq1[i] == 0 && freq2[i] > 0 || freq2[i] == 0 && freq1[i] > 0) {
                return false;
            }
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return equal(freq1.begin(), freq1.end(), freq2.begin());
    }

   private:
    vector<int> obtain_signature(const std::string& word) {
        // * The idea to use char map -> vector
        // reduce memory usage.
        vector<int> char_freq(26, 0);
        for (const auto& c : word) {
            char_freq[c - 'a']++;
        }
        return char_freq;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"bca"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

// @lcpr case=start
// "cabbba"\n"abbccc"\n
// @lcpr case=end

 */
