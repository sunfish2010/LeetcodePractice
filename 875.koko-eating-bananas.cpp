/*
 * @lc app=leetcode id=875 lang=cpp
 * @lcpr version=21913
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        int right = 0;
        for (const auto& pile : piles) {
            sum += pile;
            right = max(pile, right);
        }
        int left = ceil(sum / static_cast<double>(h));
        const auto count_hours = [&piles](int num_per_h) {
            int hours = 0;
            for (const auto& pile : piles) {
                hours += ceil(pile / static_cast<double>(num_per_h));
            }
            return hours;
        };
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (count_hours(mid) > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */
