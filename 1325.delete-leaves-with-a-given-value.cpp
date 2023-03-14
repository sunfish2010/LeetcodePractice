/*
 * @lc app=leetcode id=1325 lang=cpp
 * @lcpr version=21801
 *
 * [1325] Delete Leaves With a Given Value
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
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(deleteNode(root, target)){
            return nullptr;
        }
        return root;   
    }

private:
    bool deleteNode(TreeNode* node, int target){
        if(!node){
            return false;
        }
        // Delete from bottom up.
        if(node->left && deleteNode(node->left, target)){
            node->left = nullptr;
        }
        if(node->right && deleteNode(node->right, target)){
            node->right = nullptr;
        }
        // Leaf node and value matches.
        if(!node->left && !node->right && node->val == target){
            node = nullptr;
            return true;
        }
        return false;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [1,2,3,2,null,2,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,3,3,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,null,2,null,2]\n2\n
// @lcpr case=end

 */


