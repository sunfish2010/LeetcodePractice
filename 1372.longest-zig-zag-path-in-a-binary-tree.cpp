/*
 * @lc app=leetcode id=1372 lang=cpp
 * @lcpr version=21912
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
    int longestZigZag(TreeNode *root) {
        visit_tree(root, true, 0);
        visit_tree(root, false, 0);
        return length;
    }

   private:
    // left as 0, right as 1.
    void visit_tree(TreeNode *node, bool visit_left, int curr_len) {
        if (!node) {
            return;
        }
        length = std::max(length, curr_len);
        // Can either zigzag or start new.
        if (visit_left) {
            visit_tree(node->left, !visit_left, curr_len + 1);
            visit_tree(node->right, true, 1);
        } else {
            visit_tree(node->right, !visit_left, curr_len + 1);
            visit_tree(node->left, false, 1);
        }
    }

    int length = 0;
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,null,1,null,null,1,1,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
