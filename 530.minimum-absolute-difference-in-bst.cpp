/*
 * @lc app=leetcode id=530 lang=cpp
 * @lcpr version=21913
 *
 * [530] Minimum Absolute Difference in BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int getMinimumDifference(TreeNode *root) {
        int min_diff = INT_MAX;
        if (!root) {
            return min_diff;
        }
        // Find max on left.
        if (root->left) {
            TreeNode *curr = root->left;
            while (curr->right) {
                curr = curr->right;
            }
            min_diff = root->val - curr->val;
        }

        if (root->right) {
            // Find min on right;
            TreeNode *curr = root->right;
            while (curr->left) {
                curr = curr->left;
            }
            min_diff = min(min_diff, curr->val - root->val);
        }

        min_diff = min(min_diff, getMinimumDifference(root->left));
        min_diff = min(min_diff, getMinimumDifference(root->right));
        return min_diff;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */
