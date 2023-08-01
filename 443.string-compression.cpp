/*
 * @lc app=leetcode id=443 lang=cpp
 * @lcpr version=21912
 *
 * [443] String Compression
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int compress(vector<char>& chars) {
        if (chars.size() == 1) {
            return chars.size();
        }
        int char_count = 1;
        int total_length = 0;
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] != chars[i - 1]) {
                // chara
                chars[total_length++] = chars[i - 1];

                if (char_count > 1) {
                    // occurance
                    for (const auto c : to_string(char_count)) {
                        chars[total_length++] = c;
                    }
                }
                char_count = 1;
            } else {
                char_count++;
            }
        }
        chars[total_length++] = chars.back();

        if (char_count > 1) {
            // occurance
            for (const auto c : to_string(char_count)) {
                chars[total_length++] = c;
            }
        }
        return total_length;
    }
};

/*
from typing import Optional, List
from collections import deque

def compress(self, chars: List[str]) -> int:
    count = 1
    length = 0
    for i in range(1, len(chars)):
        if chars[i - 1] != chars[i]:
            chars[length] = chars[i - 1]
            length += 1

            if count > 1:
                str_count = str(count)
                chars[length:length + len(str_count)] = list(str_count)
                length += len(str_count)
            count = 1
        else:
            count += 1
    chars[length] = chars[-1]
    length += 1
    if count > 1:
        str_count = str(count)
        chars[length:length + len(str_count)] = list(str_count)
        length += len(str_count)
    return length

*/
// @lc code=end

/*
// @lcpr case=start
// ["a","a","b","b","c","c","c"]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","b","b","b","b","b","b","b","b","b","b","b"]\n
// @lcpr case=end

 */
