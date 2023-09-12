/*
 * @lc app=leetcode id=310 lang=cpp
 * @lcpr version=21913
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0) {
            return {};
        }
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> degrees(n, 0);
        vector<int> results;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) {
                leaves.push(i);
            }
        }
        while (!leaves.empty()) {
            results.clear();
            int width = leaves.size();
            results.reserve(width);
            for (int i = 0; i < width; ++i) {
                const int curr_node = leaves.front();
                leaves.pop();
                results.push_back(curr_node);
                for (const auto& neighbor : adj[curr_node]) {
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        return results;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n[[1,0],[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]\n
// @lcpr case=end

 */
