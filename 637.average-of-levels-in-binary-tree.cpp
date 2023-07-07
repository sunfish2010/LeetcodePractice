/*
 * @lc app=leetcode id=637 lang=cpp
 * @lcpr version=21909
 *
 * [637] Average of Levels in Binary Tree
 */

// @lc code=start
// Definition for a binary tree node.
#include <queue>
#include <utility>
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

// Tree traversal
class Solution {
   public:
    vector<double> averageOfLevels(TreeNode *root) {
        traverse_tree(1, root);
        std::vector<double> results;
        for (const auto &[sum, count] : level_sum_) {
            results.push_back(sum / count);
        }
        return results;
    }

   private:
    void traverse_tree(int level, TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        if (level > level_sum_.size()) {
            level_sum_.push_back({node->val, 1});
        } else {
            level_sum_[level - 1].first += node->val;
            level_sum_[level - 1].second++;
        }
        traverse_tree(level + 1, node->left);
        traverse_tree(level + 1, node->right);
    }
    // Uses extra memory to keep track of sum for each level.
    vector<pair<double, int>> level_sum_;
};

// BFS search on each level first.
class Solution {
   public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> results;
        queue<TreeNode *> bfs_queue;
        bfs_queue.push(root);
        while (!bfs_queue.empty()) {
            // Keep track of the number of elements at each level.
            int num_elements_level = bfs_queue.size();
            double sum = 0;
            for (int i = 0; i < num_elements_level; ++i) {
                TreeNode *node = bfs_queue.front();
                bfs_queue.pop();
                sum += node->val;
                if (node->left) {
                    bfs_queue.push(node->left);
                }
                if (node->right) {
                    bfs_queue.push(node->right);
                }
            }
            results.push_back(sum / static_cast<double>(num_elements_level));
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [3,9,20,15,7]\n
// @lcpr case=end

 */
