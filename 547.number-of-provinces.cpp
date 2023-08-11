/*
 * @lc app=leetcode id=547 lang=cpp
 * @lcpr version=21913
 *
 * [547] Number of Provinces
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            count++;
            dfs(isConnected, visited, n, i);
        }
        return count;
    }

   private:
    void dfs(const vector<vector<int>>& connected, vector<bool>& visited, int n, int i) {
        for (int j = 0; j < n; ++j) {
            if (connected[i][j] && !visited[j]) {
                visited[j] = true;
                dfs(connected, visited, n, j);
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,1,0],[1,1,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n
// @lcpr case=end

 */
