#include <vector>
using namespace std;

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build_tree(preorder, inorder, 0, preorder.size() - 1);
    }

   private:
    TreeNode* build_tree(const vector<int>& preorder, const vector<int>& inorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int root_val = preorder[root_index++];
        TreeNode* root_node = new TreeNode(root_val);
        // Leaf node.
        if (left == right) {
            return root_node;
        }
        const int root_inorder_idx = find(inorder.begin() + left, inorder.begin() + right, root_val) - inorder.begin();
        int left_subtree_right = root_inorder_idx - 1;
        int right_subtree_left = root_inorder_idx + 1;
        root_node->left = build_tree(preorder, inorder, left, left_subtree_right);
        if (root_node->left) {
            root_node->right = build_tree(preorder, inorder, right_subtree_left, right);
        } else {
            root_node->right = build_tree(preorder, inorder, right_subtree_left, right);
        }
        return root_node;
    }

    int root_index = 0;
};