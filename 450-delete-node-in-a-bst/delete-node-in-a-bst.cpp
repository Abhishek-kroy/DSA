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
    TreeNode* getans(TreeNode* root,int key){
        if(!root){
            return root;
        }               

        if(root->val==key && !root->left && !root->right){
            delete root;

            return NULL;        
        }

        if(root->val==key){
            if(!root->right){

                TreeNode* l=root->left;

                delete root;                 

                return l;    
            }

            TreeNode* r=root->right;

            while(r->left){
                r=r->left;
            }

            root->val=r->val;

            root->right=getans(root->right,r->val);      

            return root; 
        }             

        if(key<root->val)
            root->left=getans(root->left,key);
        else
            root->right=getans(root->right,key); 

            return root;                         


    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        return getans(root,key);
        
    }
};