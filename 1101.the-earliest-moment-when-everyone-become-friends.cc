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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UnionFind uf(n);
        sort(logs.begin(), logs.end(), [](const vector<int>&log_a, const vector<int>&log_b){
            return log_a[0] < log_b[0];
        });
        for(const auto& log: logs){
            if(uf.find(log[1]) != uf.find(log[2])){
                n--;
                if(n == 1){
                    return log[0];
                }
                uf.union_set(log[1], log[2]);
            }
        }
        if(n>1){
            return -1;
        }
        return logs.back()[0];
    }
    
};