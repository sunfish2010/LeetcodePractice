/*
 * @lc app=leetcode id=1161 lang=cpp
 * @lcpr version=21912
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.

 */
#include <climits>
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
    int maxLevelSum(TreeNode *root) {
        int max_sum = INT_MIN;
        int max_level = 0;
        queue<TreeNode *> nodes;
        nodes.push(root);
        int level = 0;
        while (!nodes.empty()) {
            int num_elements_in_level = nodes.size();
            int curr_sum = 0;
            level++;
            for (int i = 0; i < num_elements_in_level; ++i) {
                TreeNode *curr_node = nodes.front();
                nodes.pop();
                curr_sum += curr_node->val;
                if (curr_node->left) {
                    nodes.push(curr_node->left);
                }
                if (curr_node->right) {
                    nodes.push(curr_node->right);
                }
            }
            if (curr_sum > max_sum) {
                max_level = level;
                max_sum = curr_sum;
            }
        }
        return max_level;
    }
};

/* Python

from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        max_sum = float("-inf")
        max_level = 0
        nodes = deque()
        nodes.append(root)
        curr_level = 0
        while nodes:
            curr_level += 1
            curr_sum = sum([node.val for node in nodes])
            if curr_sum > max_sum:
                max_sum = curr_sum
                max_level = curr_level
            for _ in range(len(nodes)):
                node = nodes.popleft()
                if node.left:
                    nodes.append(node.left)
                if node.right:
                    nodes.append(node.right)
        return max_level

*/
// @lc code=end

/*
// @lcpr case=start
// [1,7,0,7,-8,null,null]\n
// @lcpr case=end

// @lcpr case=start
// [989,null,10250,98693,-89388,null,null,null,-32127]\n
// @lcpr case=end

 */
