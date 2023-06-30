/*
 * @lc app=leetcode id=11 lang=cpp
 * @lcpr version=21909
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            // Area formula.
            max_area = max(max_area, (right - left) * min(height[left], height[right]));
            // Keep the higher barrier for more water.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */
