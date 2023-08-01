/*
 * @lc app=leetcode id=450 lang=cpp
 * @lcpr version=21912
 *
 * [450] Delete Node in a BST
 */

// @lc code=start
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            // root has key.
            if (!root->left && !root->right) {
                return nullptr;
            } else if (!root->right || !root->left) {
                return root->right ? root->right : root->left;
            } else {
                TreeNode* pre = predecessor(root);
                root->val = pre->val;
                root->left = deleteNode(root->left, root->val);
            }
        }

        return root;
    }

   private:
    TreeNode* predecessor(TreeNode* node) {
        node = node->left;
        while (node->right) {
            node = node->right;
        }
        return node;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,3,6,2,4,null,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n0\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
