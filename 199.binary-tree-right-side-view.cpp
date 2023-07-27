/*
 * @lc app=leetcode id=199 lang=cpp
 * @lcpr version=21912
 *
 * [199] Binary Tree Right Side View
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
#include <vector>
using namespace std;

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
    vector<int> rightSideView(TreeNode *root) {
        traverse_tree(root, 0);
        return right_side_view;
    }

   private:
    void traverse_tree(TreeNode *node, int level) {
        if (!node) {
            return;
        }
        if (right_side_view.size() == level) {
            right_side_view.push_back(node->val);
        }
        traverse_tree(node->right, level + 1);
        traverse_tree(node->left, level + 1);
    }

    vector<int> right_side_view;
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
