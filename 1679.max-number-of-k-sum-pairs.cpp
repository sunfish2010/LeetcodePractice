/*
 * @lc app=leetcode id=1679 lang=cpp
 * @lcpr version=21912
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int num_ops = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) {
                num_ops++;
                left++;
                right--;
            } else if (sum < k) {
                left++;
            } else {
                right--;
            }
        }
        return num_ops;
    }
};

/*

def maxOperations(self, nums: List[int], k: int) -> int:
    nums.sort()
    left = 0
    right = len(nums) - 1
    num_ops = 0
    while left < right:
        sum = nums[left] + nums[right]
        if sum == k:
            num_ops += 1
            left += 1
            right -= 1
        elif sum < k:
            left += 1
        else:
            right -= 1
    return num_ops

*/
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,1,3,4,3]\n6\n
// @lcpr case=end

 */
