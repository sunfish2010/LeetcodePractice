/*
 * @lc app=leetcode id=1448 lang=cpp
 * @lcpr version=21912
 *
 * [1448] Count Good Nodes in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.

 */
#include <climits>

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
    int goodNodes(TreeNode *root) {
        traverse_tree(root, INT_MIN);
        return num_good_nodes;
    }

   private:
    void traverse_tree(TreeNode *node, int curr_max) {
        if (!node) {
            return;
        }
        if (node->val >= curr_max) {
            num_good_nodes++;
        }
        curr_max = std::max(curr_max, node->val);
        traverse_tree(node->left, curr_max);
        traverse_tree(node->right, curr_max);
    }

    int num_good_nodes = 0;
};
/* Python
class Solution:
    def __init__(self):
        self.num_good_nodes_ = 0

    def traverse_node(self, node: TreeNode, curr_max: float) -> None:
        if node is None:
            return
        if node.val >= curr_max:
            self.num_good_nodes_ += 1
        curr_max = max(curr_max, node.val)
        self.traverse_node(node.left, curr_max)
        self.traverse_node(node.right, curr_max)

    def goodNodes(self, root: TreeNode) -> int:
        self.traverse_node(root, float("-inf"))
        return self.num_good_nodes_

*/
// @lc code=end

/*
// @lcpr case=start
// [3,1,4,3,null,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,null,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
