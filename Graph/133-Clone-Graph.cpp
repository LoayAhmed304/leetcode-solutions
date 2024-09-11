/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& New){
        if(!node) return nullptr;

        
        if(New[node]) return New[node];  // If node was already copied

        // Create a copy and append to the New hashmap
        Node* copy = new Node(node->val);
        New[node] = copy;

        // Recursive call on every neighbour
        for(auto nei: node->neighbors){
            copy->neighbors.push_back(dfs(nei, New));
        }
      
        return copy;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*>New;
        
        return dfs(node, New);
    }
};
