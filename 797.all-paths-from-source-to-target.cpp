#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        num_nodes = graph.size();
        visited = vector<bool>(num_nodes, false);
        vector<int> path = {0};
        visited[0] = true;
        dfs(graph, path);
        return all_paths;
    }

    void dfs(const vector<vector<int>>&graph, vector<int>&curr_path){
        if(curr_path.back() == num_nodes - 1){
            all_paths.push_back(curr_path);
            return;
        }
        for(const auto& neighbor: graph[curr_path.back()]){
            if(visited[neighbor]){
                continue;
            }
            visited[neighbor] = true;
            curr_path.push_back(neighbor);
            dfs(graph, curr_path);
            curr_path.pop_back();
            visited[neighbor] = false;
        }
    }

private:

int num_nodes = 0;
vector<bool> visited;
vector<vector<int>> all_paths;
};