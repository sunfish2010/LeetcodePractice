/*
 * @lc app=leetcode id=104 lang=cpp
 * @lcpr version=21912
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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
        int maxDepth(TreeNode *root) {
        return traverse_tree(root);
    }

   private:
    int traverse_tree(TreeNode *node) {
        if (!node) {
            return 0;
        }
       
        int left_height = traverse_tree(node->right) + 1;
        int right_height = traverse_tree(node->left) + 1;
        return max(left_height, right_height);
    }
};

/*

 int depth = 0;
        if (!root) {
        return depth;
        }
        queue<TreeNode *> to_visit;
        to_visit.push(root);
        while (!to_visit.empty()) {
            int num_nodes = to_visit.size();
            depth++;
            for (int i = 0; i < num_nodes; ++i) {
                TreeNode *node = to_visit.front();
                to_visit.pop();
                if (node->left) {
                to_visit.push(node->left);
                }
                if (node->right) {
                to_visit.push(node->right);
                }
            }
        }
        return depth;

*/
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */
