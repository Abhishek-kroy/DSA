/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int gettotal(TreeNode* root,unordered_map<TreeNode*,int>& depth,int dpt){
        if(!root){
            return 0;
        }            

        depth[root]=dpt; 

        return 1+gettotal(root->left,depth,dpt+1)+gettotal(root->right,depth,dpt+1);                    
    }

    void getup(TreeNode* root,TreeNode* par,unordered_map<TreeNode*,vector<TreeNode*>>& up,int LOG,int n){
        if(!root){
            return ;
        }

        up[root].resize(LOG+1);

        for(int i=0;i<=LOG;i++){
            if(i-1>=0)
                up[root][i]=up[up[root][i-1]][i-1];        
            else
                up[root][i]=par; 
        }

        getup(root->left,root,up,LOG,n);
        getup(root->right,root,up,LOG,n);        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,int> depth;        

        int n=gettotal(root,depth,0);      

        unordered_map<TreeNode*,vector<TreeNode*>> up;

        int LOG =log2(n)+1;

        up[root].resize(LOG+1);

        for(int i=0;i<=LOG;i++){
            up[root][i]=root;
        }  


        getup(root,root,up,LOG,n);   

        if(depth[p]>depth[q]){
            swap(p,q);
        }     

        int d=depth[q]-depth[p];    

        for(int i=LOG;i>=0;i--){
            if(d&(1<<i)){
                q=up[q][i];
            }
        }        

        if(p==q){
            return p;
        }

        for(int i=LOG;i>=0;i--){
            if(up[p][i]!=up[q][i]){
                p=up[p][i];
                q=up[q][i];
            }                                    
        }

        return up[p][0]; 

        
    }
};