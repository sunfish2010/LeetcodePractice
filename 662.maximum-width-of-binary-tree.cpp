/*
 * @lc app=leetcode id=662 lang=cpp
 * @lcpr version=21913
 *
 * [662] Maximum Width of Binary Tree
 */

// @lc code=start
#include <queue>
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
    int widthOfBinaryTree(TreeNode *root) {
        /*
        IMPORTANT:
            make sure to know the indexing of nodes in binary tree.
            parent, child, etc.
        */
        queue<pair<TreeNode *, unsigned long long>> nodes;
        nodes.push({root, 0});
        unsigned long long max_width = 0;
        while (!nodes.empty()) {
            // number of nodes in level.
            int size = nodes.size();
            unsigned long long min_idx = nodes.front().second;
            unsigned long long max_idx = nodes.back().second;
            max_width = max(max_width, max_idx - min_idx + 1);
            for (int i = 0; i < size; ++i) {
                auto node = nodes.front().first;
                auto idx = nodes.front().second - min_idx;
                nodes.pop();
                if (node->left) {
                    nodes.push({node->left, 2 * idx});
                }
                if (node->right) {
                    nodes.push({node->right, 2 * idx + 1});
                }
            }
        }
        return max_width;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,2,5,3,null,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5,null,null,9,6,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5]\n
// @lcpr case=end

 */
