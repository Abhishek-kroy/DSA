/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*,TreeNode*> getans(TreeNode* root){
        if(!root){
            return {root,root};      
        }

        auto [l1,r1]=getans(root->left);
        auto [l2,r2]=getans(root->right);

        if(l1){
            root->right=l1;
        }
        else if(l2){
            root->right=l2; 
        }
        else{
            root->right=NULL;             
        }

        root->left=NULL; 

        if(r1){
            r1->right=l2;  
        }



        auto l= root; 

        auto r= r2==NULL ?  r1==NULL ? root : r1: r2 ;        

        return {l,r};
    }
    void flatten(TreeNode* root) {
        auto [l,r]=getans(root);        
    }
};