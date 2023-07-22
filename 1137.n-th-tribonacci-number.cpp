/*
 * @lc app=leetcode id=1137 lang=cpp
 * @lcpr version=21912
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int tribonacci(int n) {
        int Tn = 0;
        int Tn1 = 1;
        int Tn2 = 1;
        if (n == 0) {
            return Tn;
        } else if (n == 1) {
            return Tn1;
        } else if (n == 2) {
            return Tn2;
        }
        for (int i = 3; i <= n; ++i) {
            int Tn3 = Tn + Tn1 + Tn2;
            Tn = Tn1;
            Tn1 = Tn2;
            Tn2 = Tn3;
        }
        return Tn2;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 25\n
// @lcpr case=end

 */
