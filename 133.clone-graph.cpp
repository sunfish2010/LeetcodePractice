
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        if(cloned_nodes.count(node)){
            return cloned_nodes[node];
        }
        Node* new_node = new Node(node->val);
        cloned_nodes[node] = new_node;
        for(auto neighbor: node->neighbors){
            new_node->neighbors.push_back(cloneGraph(neighbor));
        }
        return new_node;
    }
private:
unordered_map<Node*, Node*> cloned_nodes;
};