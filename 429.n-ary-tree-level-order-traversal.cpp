#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return {{}};
        }
        queue<Node*> level_nodes;
        vector<vector<int>> level_order;
        level_nodes.push(root);
        while (!level_nodes.empty())
        {
            int num_nodes = level_nodes.size();
            vector<int> curr_level(num_nodes);
            for(int i = 0; i < num_nodes; ++i){
                Node* curr = level_nodes.front();
                curr_level[i] = curr->val; 
                level_nodes.pop();
                for(auto node: curr->children){
                    level_nodes.push(node);
                }
            }
            level_order.push_back(curr_level);
        }
        return level_order;
    }
};