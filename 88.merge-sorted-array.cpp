/*
 * @lc app=leetcode id=88 lang=cpp
 * @lcpr version=21913
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx_1 = m - 1;
        int idx_2 = n - 1;
        int idx = m + n - 1;
        while (idx_1 >= 0 && idx_2 >= 0) {
            if (nums1[idx_1] > nums2[idx_2]) {
                nums1[idx] = nums1[idx_1--];
            } else {
                nums1[idx] = nums2[idx_2--];
            }
            idx--;
        }
        while (idx_2 >= 0) {
            nums1[idx--] = nums2[idx_2--];
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,0,0,0]\n3\n[2,5,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n[]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n[1]\n1\n
// @lcpr case=end

 */
