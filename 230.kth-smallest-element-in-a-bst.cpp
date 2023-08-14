/*
 * @lc app=leetcode id=230 lang=cpp
 * @lcpr version=21913
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start

#include <stack>
using namespace std;

/**
 * Definition for a binary tree node. */

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
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> nodes_to_visit;
        // the smaller elements are always on the left, thus visit all left nodes first;
        // in order traversal.
        TreeNode *curr = root;
        while (true) {
            while (curr != nullptr) {
                nodes_to_visit.push(curr);
                curr = curr->left;
            }
            // Now we have found all elements on the left side
            curr = nodes_to_visit.top();
            nodes_to_visit.pop();
            k--;
            if (k == 0) {
                return curr->val;
            }
            curr = curr->right;
        }
        return -1;
    }
};

/* Initial more complicated preorder traversal solution.

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        rank_of_node(root, 0);
        return ans;
    }

private:
    int rank_of_node(TreeNode* node,  int curr){
        if(!node){
            return 0;
        }
        int num_left_nodes = rank_of_node(node->left, curr);
        // Answer has been found.
        if(num_left_nodes == -1){
            return -1;
        }
        // left node is the kthSmallest.
        if(k_ == num_left_nodes + curr){
            ans = node->left->val;
            return -1;
        }
        // curr node is the kthSmallest
        if(k_ == num_left_nodes + curr + 1){
            ans = node->val;
            return -1;
        }
        int num_right_nodes = rank_of_node(node->right, num_left_nodes + curr +                                      1);
        // Answer has been found;
        if(num_right_nodes == -1){
            return -1;
        }
        return num_right_nodes + num_left_nodes + 1;
    }

    int k_ = 0;
    int ans = -1;
};

*/
// @lc code=end

/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */
