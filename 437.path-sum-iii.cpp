/*
 * @lc app=leetcode id=437 lang=cpp
 * @lcpr version=21909
 *
 * [437] Path Sum III
 */

// @lc code=start
#include <unordered_map>
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
    int pathSum(TreeNode *root, int targetSum) {
        target = targetSum;
        preorder(root, 0);
        return count;
    }

   private:
    void preorder(TreeNode *node, long int currSum) {
        if (!node) {
            return;
        }
        currSum += node->val;
        if (currSum == target) {
            ++count;
        }
        // This is like dp. If there is a path sum = currSum - target,
        // we can eliminate that path and get the targetSum.
        count += prefix_sum[currSum - target];
        prefix_sum[currSum]++;
        preorder(node->left, currSum);
        preorder(node->right, currSum);
        prefix_sum[currSum]--;
    }

    int count = 0;
    int target = 0;
    unordered_map<long int, int> prefix_sum;
};
// @lc code=end

/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */
