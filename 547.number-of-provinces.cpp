/*
 * @lc app=leetcode id=547 lang=cpp
 * @lcpr version=21913
 *
 * [547] Number of Provinces
 */

// @lc code=start
#include <vector>
using namespace std;

// DFS solution
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

/* Union Find Solution.

class UnionFind {
   public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_set(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

   private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        size_t n = isConnected.size();
        UnionFind circle(n);
        int num = n;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (isConnected[i][j] && circle.find(i) != circle.find(j)) {
                    num--;
                    circle.union_set(i, j);
                }
            }
        }
        return num;
    }
};

*/
// @lc code=end

/*
// @lcpr case=start
// [[1,1,0],[1,1,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n
// @lcpr case=end

 */
