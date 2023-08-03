/*
 * @lc app=leetcode id=110 lang=cpp
 * @lcpr version=21912
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.*/
#include <algorithm>
#include <cmath>

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
    bool isBalanced(TreeNode *root) {
        d_of_tree(root);
        return is_balanced;
    }

   private:
    int d_of_tree(TreeNode *node) {
        if (!node) {
            return -1;
        }
        // Leaf node.
        if (!node->left && !node->right) {
            return 0;
        }
        int left_depth = 1 + d_of_tree(node->left);
        int right_depth = 1 + d_of_tree(node->right);
        if (abs(left_depth - right_depth) > 1) {
            is_balanced = false;
        }
        return std::max(left_depth, right_depth);
    }

    bool is_balanced = true;
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
