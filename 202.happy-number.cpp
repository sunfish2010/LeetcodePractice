/*
 * @lc app=leetcode id=202 lang=cpp
 * @lcpr version=21913
 *
 * [202] Happy Number
 */

// @lc code=start
#include <cmath>
using namespace std;
class Solution {
   public:
    bool isHappy(int n) {
        int slow = n;
        int fast = sum_of_digits(n);
        while (fast != slow && fast != 1) {
            fast = sum_of_digits(sum_of_digits(fast));
            slow = sum_of_digits(slow);
        }
        if (fast == 1) {
            return true;
        }
        return false;
    }

   private:
    int sum_of_digits(int num) {
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num = floor(num / 10);
        }
        return sum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 19\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */
