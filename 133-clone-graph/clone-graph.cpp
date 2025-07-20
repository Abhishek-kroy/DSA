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
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        queue<pair<Node*,Node*>> q;
        unordered_map<int,Node*> visited;
        Node* graph=new  Node(node->val);
        q.push({graph,node});
        visited[graph->val]=graph;
        while(!q.empty()){
            auto [g,n]=q.front();
            q.pop();
            for(auto nei:n->neighbors){
                if(visited.find(nei->val)==visited.end()){
                    Node* neinode=new Node(nei->val);
                    visited[nei->val]=neinode;
                    g->neighbors.push_back(neinode);
                    q.push({neinode,nei});
                }
                else{
                    Node* neinode=visited[nei->val];
                    g->neighbors.push_back(neinode);
                }
            }
        }

        return graph;

    }
};