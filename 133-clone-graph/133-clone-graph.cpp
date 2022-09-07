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
    void dfs(Node* node, Node* clone, vector<Node*> &visited){
        visited[node->val] = clone;
        
        for(auto x:node->neighbors){
            if(!visited[x->val]){
                Node* newNode = new Node(x->val);
                clone->neighbors.push_back(newNode);
                dfs(x, newNode, visited);
            }
            else{
                clone->neighbors.push_back(visited[x->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        vector<Node*> visited(1000, NULL);
        
        Node* clone = new Node(node->val);
        visited[node->val] = clone;
        dfs(node, clone, visited);
        return clone;
    }
};