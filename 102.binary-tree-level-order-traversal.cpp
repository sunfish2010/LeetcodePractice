/*
 * @lc app=leetcode id=102 lang=cpp
 * @lcpr version=21913
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) {
            return {{}};
        }
        vector<vector<int>> level_order;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            vector<int> curr(nodes.size());
            for (int i = 0; i < curr.size(); ++i) {
                const auto node = nodes.front();
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
                curr[i] = node->val;
                nodes.pop();
            }
            level_order.push_back(curr);
        }
        return level_order;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
