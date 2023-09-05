/*
 * @lc app=leetcode id=1089 lang=cpp
 * @lcpr version=21913
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
   public:
    void duplicateZeros(vector<int>& arr) {
        int num_zeros = 0;
        int i = 0;
        for (i = 0; i < arr.size(); ++i) {
            num_zeros += arr[i] == 0;
            if (i + num_zeros >= arr.size() - 1) {
                break;
            }
        }
        int j = arr.size() - 1;
        // This only occur when the last "valid" cell is a zero, and the arr is not long enough to pad two zeros.
        if (i + num_zeros > arr.size() - 1) {
            arr.back() = 0;
            i--;
            j--;
        }
        while (j >= 0) {
            if (arr[i] == 0) {
                arr[j] = 0;
                if (j - 1 >= 0) {
                    arr[j - 1] = 0;
                }
                j -= 2;
            } else {
                arr[j] = arr[i];
                j--;
            }
            i--;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,2,3,0,4,5,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
