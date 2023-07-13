/*
 * @lc app=leetcode id=114 lang=cpp
 * @lcpr version=21909
 *
 * [114] Flatten Binary Tree to Linked List
 */

// @lc code=start

// Definition for a binary tree node.
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
    void flatten(TreeNode *root) {
        flatten_trees(root);
    }

   private:
    // Flatten node and return the last node of the flattened list.
    TreeNode *flatten_trees(TreeNode *node) {
        // Single leaf node;
        if (!node->left && !node->right) {
            return node;
        }
        // One sided tree, flatten it and then return the end of trees.
        if (!node->left) {
            return flatten_trees(node->right);
        }
        if (!node->right) {
            TreeNode *left_end = flatten_trees(node->left);
            node->right = node->left;
            node->left = nullptr;
            return left_end;
        }
        TreeNode *left_end = flatten_trees(node->left);
        TreeNode *right_end = flatten_trees(node->right);
        left_end->right = node->right;
        node->right = node->left;
        node->left = nullptr;
        return right_end;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
