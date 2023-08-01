/*
 * @lc app=leetcode id=1456 lang=cpp
 * @lcpr version=21912
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    int maxVowels(string s, int k) {
        /* original solution, uses queue, but a sliding window approach can solve this issue

         int left = 0;
        int max_num_vowels = 0;
        queue<int> vowel_indices;
        int curr_num_vowels = 0;

        // iterate i, push vowel indices to queue.
        // if i - left >k, left = first idx in queue, num_vowels = size of queue.
        for (int i = 0; i < s.size(); ++i) {
            if (i - left + 1 > k) {
                max_num_vowels = max(max_num_vowels, curr_num_vowels);
                if (!vowel_indices.empty()) {
                    left = vowel_indices.front();
                    curr_num_vowels = vowel_indices.size();
                    vowel_indices.pop();
                } else {
                    left = i;
                    curr_num_vowels = 0;
                }
            }
            if (vowels.find(s[i]) != vowels.end()) {
                curr_num_vowels++;
                if (left != i) {
                    vowel_indices.push(i);
                }
            }
        }

        if (left + k >= s.size()) {
            int num_char_left = k - (s.size() - left);
            if (left + 1 - num_char_left >= 0) {
                max_num_vowels = max(max_num_vowels, curr_num_vowels);
            }
        }
        return max_num_vowels;

        */

        /*  Let count be the number of vowels in the current window [i - k, i - 1]. If we move the window one character to the right as [i - k + 1, i].
                If the newly added character s[i] is a vowel, we increase count by 1.
                If the newly removed character s[i - k] is a vowel, we reduce count by 1.
        */
        static const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int curr_count = 0;
        for (int i = 0; i < k; ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                curr_count++;
            }
        }
        int max_count = curr_count;

        for (int i = k; i < s.size(); ++i) {
            curr_count += vowels.count(s[i]) - vowels.count(s[i - k]);
            max_count = max(curr_count, max_count);
        }
        return max_count;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abciiidef"\n3\n
// @lcpr case=end

// @lcpr case=start
// "aeiou"\n2\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n3\n
// @lcpr case=end

 */
