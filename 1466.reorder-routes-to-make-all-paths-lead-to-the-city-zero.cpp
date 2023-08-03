/*
 * @lc app=leetcode id=1466 lang=cpp
 * @lcpr version=21913
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> edges(n);
        for (const auto& connection : connections) {
            int src = connection[0];
            int dst = connection[1];
            edges[src].push_back({dst, 1});
            edges[dst].push_back({src, 0});
        }
        vector<bool> visit(n, false);
        dfs(edges, visit, 0);
        return count;
    }

   private:
    void dfs(const vector<vector<pair<int, int>>>& edges, vector<bool>& visit, int src) {
        visit[src] = true;
        for (auto& [neighbor, sign] : edges[src]) {
            if (!visit[neighbor]) {
                count += sign;
                visit[neighbor] = true;
                dfs(edges, visit, neighbor);
            }
        }
    }

    int count = 0;
};
// @lc code=end

/*
// @lcpr case=start
// 6\n[[0,1],[1,3],[2,3],[4,0],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,0],[1,2],[3,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,0],[2,0]]\n
// @lcpr case=end

 */
