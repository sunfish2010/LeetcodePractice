#include <vector>
using namespace std;

class UnionFind{
public:  
    UnionFind(int n): parent(n), rank(n, 0){
        for(int i = 0; i < n;++i){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(x!=parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void union_set(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }else if(rank[parent_y] < rank[parent_x]){
            parent[parent_y] = parent[parent_x];
        }else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = n;
        UnionFind union_find(n);
        for(const auto&edge: edges){
            int node_a = edge[0];
            int node_b = edge[1];
            if(union_find.find(node_a)!=union_find.find(node_b)){
                union_find.union_set(node_b, node_a);
                count--;
            }
        }
        return count;
    }
};