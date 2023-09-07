/*
 * @lc app=leetcode id=424 lang=cpp
 * @lcpr version=21913
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    int characterReplacement(string s, int k) {
        int left = 0;
        vector<int> freq(26, 0);
        int max_freq = 0;
        int max_length = 1;
        for (int right = 0; right < s.size(); ++right) {
            int curr_idx = s[right] - 'A';
            freq[curr_idx]++;
            max_freq = max(max_freq, freq[curr_idx]);
            if (right - left + 1 - max_freq <= k) {
                max_length = right - left + 1;
            } else {
                // Pop left since current window cannot be valid, keep window size at (l-1) and find potential l
                // The window can only be valid again if max_freq got updated.
                freq[s[left] - 'A']--;
                left++;
            }
        }
        return max_length;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ABAB"\n2\n
// @lcpr case=end

// @lcpr case=start
// "AABABBA"\n1\n
// @lcpr case=end

 */
