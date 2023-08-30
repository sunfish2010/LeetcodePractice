
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return nullptr;
        }
        queue<Node*> level_nodes;
        level_nodes.push(root);
        while (!level_nodes.empty())
        {
            int num_nodes = level_nodes.size();
            for(int i = 0; i < num_nodes; ++i){
                Node* curr = level_nodes.front();
                level_nodes.pop();
                curr->next = i == num_nodes -1? nullptr: level_nodes.front();
                if(curr->left){
                    level_nodes.push(curr->left);
                }
                if(curr->right){
                    level_nodes.push(curr->right);
                }
            }
        }
        return root;
        
    }
};