#include <vector>
#include <string>
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        for(const auto&pair: pairs){
            if(uf.find(pair[0])!= uf.find(pair[1])){
                uf.union_set(pair[0], pair[1]);
            }
        }
        unordered_map<int, vector<int>> components;
        for(int i = 0; i < s.size(); ++i){
            components[uf.find(i)].push_back(i);
        }
        string smallest = s;
        for(const auto&[root, indices]:components){
            vector<char> chars;
            std::transform(indices.begin(), indices.end(), back_inserter(chars), [&s](const int index){
                return s[index];
            });
            sort(chars.begin(), chars.end());
            for(int i = 0; i < chars.size(); ++i){
                smallest[indices[i]] = chars[i];
            }
        }
        return smallest;
    }
};