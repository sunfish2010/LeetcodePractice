/*
 * @lc app=leetcode id=1584 lang=cpp
 * @lcpr version=21913
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start

#include <vector>
using namespace std;
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

struct Edge {
    size_t src;
    size_t dst;
    int weight;
    friend bool operator<(const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    }
};

class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // Compute edges and sort edges.
        vector<Edge> edges;
        const auto dist_fcn = [](const vector<int>& point_a, const vector<int>& point_b) {
            return abs(point_a[0] - point_b[0]) + abs(point_a[1] - point_b[1]);
        };
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                edges.push_back(Edge{.src = i, .dst = j, .weight = dist_fcn(points[i], points[j])});
            }
        }
        sort(edges.begin(), edges.end());

        UnionFind uf(n);
        int total_dist = 0;
        int num_edges = 0;
        for (const auto& edge : edges) {
            if (uf.find(edge.src) != uf.find(edge.dst)) {
                uf.union_set(edge.src, edge.dst);
                total_dist += edge.weight;
                num_edges++;
            }
            if (num_edges == n - 1) {
                break;
            }
        }
        return total_dist;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0],[2,2],[3,10],[5,2],[7,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,12],[-2,5],[-4,1]]\n
// @lcpr case=end

 */
