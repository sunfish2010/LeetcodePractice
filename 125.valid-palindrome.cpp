/*
 * @lc app=leetcode id=125 lang=cpp
 * @lcpr version=21913
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
   public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() -1;
        const auto is_valid = [](char c){
            return isalpha(c) || isdigit(c);
        };
        while(left < right){
            while(left < right && !is_valid(s[left])){
                left++;
            }
            while(left < right && !is_valid(s[right])){
                right--;
            }
            if(left >= right){
                break;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

/*
class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1
        while True:
            while left < right and not (s[left].isalpha() or s[left].isnumeric()):
                left += 1
            while left < right and not (s[right].isalpha() or s[right].isnumeric()):
                right -= 1
            if left >= right:
                break
            if not s[left].lower() == s[right].lower():
                return False
            left += 1
            right -= 1
        return True

*/
// @lc code=end

/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// " "\n
// @lcpr case=end

 */
