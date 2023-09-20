/*
 * @lc app=leetcode id=222 lang=cpp
 * @lcpr version=21913
 *
 * [222] Count Complete Tree Nodes
 */

// @lc code=start
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
    int countNodes(TreeNode *root) {
        int count = 0;
        int d = depth_of_tree(root);
        while (root) {
            // Left tree is a complete tree of d - 1
            if (depth_of_tree(root->right) == d - 1) {
                root = root->right;
                count += 1 << d;
            } else {
                // Right tree is complete tree of d -2
                root = root->left;
                count += 1 << (d - 1);
            }
            d--;
        }
        return count;
    }

   private:
    // This only works because it's a complete tree.
    int depth_of_tree(TreeNode *root) {
        if (!root) {
            return -1;
        }
        int d = 0;
        while (root && root->left) {
            d++;
            root = root->left;
        }
        return d;
    }
};

/*
return root ? 1 + countNodes(root->right) + countNodes(root->left) : 0;

*/
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
