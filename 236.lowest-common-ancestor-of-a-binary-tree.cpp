/*
 * @lc app=leetcode id=236 lang=cpp
 * @lcpr version=21912
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find_node(root, p, q);
        return lca_;
    }

   private:
    bool find_node(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return false;
        }
        if (p->val == root->val || q->val == root->val) {
            lca_ = root;
            return true;
        }
        // values on both sides of trees.
        const auto left_found = find_node(root->left, p, q);
        const auto right_found = find_node(root->right, p, q);
        if (right_found && left_found) {
            lca_ = root;
            return true;
        }
        return right_found || left_found;
    }

    TreeNode* lca_;
};

/*

class Solution:
    def __init__(self):
        self.lcw_ = None

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.found_node(root, p, q)
        return self.lcw_

    def found_node(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> bool:
        if not root:
            return False
        if p.val == root.val or q.val == root.val:
            self.lcw_ = root
            return True
        left_lca = self.found_node(root.left, p, q)
        right_lca = self.found_node(root.right, p, q)
        if left_lca and right_lca:
            self.lcw_ = root
            return True
        return left_lca or right_lca

*/
// @lc code=end

/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */
