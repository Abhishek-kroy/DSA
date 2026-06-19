/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }

        root->next=NULL; 

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();

            Node* prev=NULL;

            while(sz--){
                Node* node=q.front();
                q.pop();

                // cout<<node->val<<endl;          

                if(prev!=NULL){
                    prev->next=node->left;
                }

                if(node->left)
                    node->left->next=node->right;        

                prev=node->right;                                      

                if(node->left)
                q.push(node->left);

                if(node->right)        
                q.push(node->right);

                // cout<<"insreted "<<node->left->val<<" "<<node->right->val<<endl; 
            }

            if(prev!=NULL)            
                prev->next=NULL;
        }

        return root; 
    }
};