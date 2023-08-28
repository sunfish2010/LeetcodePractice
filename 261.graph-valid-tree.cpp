
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

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind helper(n);
        if(edges.size() != n-1){
            return false;
        }
        for(const auto&edge: edges){
            int node_a = edge[0];
            int node_b = edge[1];
            if(helper.find(node_a)!=helper.find(node_b)){
                helper.union_set(node_b, node_a);
            }else{
                return false;
            }
        }
        return true;
    }
};
