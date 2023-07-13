/*
 * @lc app=leetcode id=1071 lang=cpp
 * @lcpr version=21909
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
#include <numeric>
#include <string>

using namespace std;

class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        int gcd_length = gcd(str1.size(), str2.size());
        return str1.substr(0, gcd_length);
    }
};

// int gcd(int a, int b) {
//     int R;
//     while ((a % b) > 0) {
//         R = a % b;
//         a = b;
//         b = R;
//     }
//     return b;
// }

// @lc code=end

/*
// @lcpr case=start
// "ABCABC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "ABABAB"\n"ABAB"\n
// @lcpr case=end

// @lcpr case=start
// "LEET"\n"CODE"\n
// @lcpr case=end

 */
