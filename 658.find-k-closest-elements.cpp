/*
 * @lc app=leetcode id=658 lang=cpp
 * @lcpr version=21913
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const auto cmp = [&x](int p1, int p2) {
            if (abs(p1 - x) == abs(p2 - x)) {
                return p1 < p2;
            }
            return abs(p1 - x) < abs(p2 - x);
        };
        std::vector<int> results;
        if (x <= arr[0]) {
            copy(arr.begin(), arr.begin() + k, back_inserter(results));
            return results;
        } else if (x >= arr.back()) {
            copy(arr.end() - k, arr.end(), back_inserter(results));
            return results;
        }
        auto iter = lower_bound(arr.begin(), arr.end(), x);
        int mid = distance(arr.begin(), iter);
        int left = mid;
        int right = mid - 1;
        int n = arr.size();
        while (right - left + 1 < k) {
            if (left > 0 && right < n - 1) {
                if (cmp(arr[left - 1], arr[right + 1])) {
                    left--;
                } else {
                    right++;
                }
            } else if (left == 0) {
                right++;
            } else if (right == n - 1) {
                left--;
            }
        }
        copy(arr.begin() + left, arr.begin() + right, back_inserter(results));
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n4\n-1\n
// @lcpr case=end

 */
