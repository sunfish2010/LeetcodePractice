/*
 * @lc app=leetcode id=543 lang=cpp
 * @lcpr version=21912
 *
 * [543] Diameter of Binary Tree
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
    int diameterOfBinaryTree(TreeNode *root) {
        d_of_tree(root);
        return max_depth;
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
        max_depth = max(max_depth, left_depth + right_depth);
        return max(left_depth, right_depth);
    }

    int max_depth = 0;
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
