/*
 * @lc app=leetcode id=872 lang=cpp
 * @lcpr version=21912
 *
 * [872] Leaf-Similar Trees
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
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> leaves1, leaves2;
        traverse_tree(root1, leaves1);
        traverse_tree(root2, leaves2);
        if (leaves1.size() != leaves2.size()) {
            return false;
        }
        for (int i = 0; i < leaves1.size(); ++i) {
            if (leaves1[i] != leaves2[i]) {
                return false;
            }
        }
        return true;
    }

   private:
    void traverse_tree(TreeNode *node, vector<int> &leaves) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            leaves.push_back(node->val);
        }
        traverse_tree(node->left, leaves);
        traverse_tree(node->right, leaves);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[1,3,2]\n
// @lcpr case=end

 */
