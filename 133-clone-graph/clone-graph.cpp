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

        unordered_map<int,Node*> f;

        Node* root=new Node(node->val);         

        f[root->val]=root; 

        queue<pair<Node*,Node*>> q;
        q.push({root,node});

        while(!q.empty()){
            auto [r,n]=q.front();
            q.pop();

            for(auto nei:n->neighbors){
                if(f.find(nei->val)==f.end()){                  
                    Node* nn=new Node(nei->val);        
                    f[nn->val]=nn;        
                    q.push({nn,nei});

                    r->neighbors.push_back(nn);
                }
                else
                    r->neighbors.push_back(f[nei->val]);
            }            
        }

        return root;        
    }
};