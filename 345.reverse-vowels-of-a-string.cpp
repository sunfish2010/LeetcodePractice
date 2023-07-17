/*
 * @lc app=leetcode id=345 lang=cpp
 * @lcpr version=21909
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
   public:
    string reverseVowels(string s) {
        if (s.empty()) {
            return s;
        }
        int start = 0;
        int end = s.size() - 1;
        const unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        while (start < end) {
            while (start < s.size() && vowels.find(s[start]) == vowels.end()) {
                ++start;
            }
            while (end >= 0 && vowels.find(s[end]) == vowels.end()) {
                --end;
            }
            if (start < end) {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "hello"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */
