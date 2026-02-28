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
    TreeNode* ans=NULL;
    void getans(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return ;
        }

        // if(root->val==p->val || root->val==q->val){
        //     ans=root;
        //     return ;
        // }    

        if(root->val>=p->val && root->val<=q->val){
            ans=root;
            return ;
        }

        if(root->val<=p->val && root->val<=q->val){
            getans(root->right,p,q);
            return ;
        }
        
        getans(root->left,p,q);            
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val){
            swap(p,q);
        }
        getans(root,p,q);     
        return ans;
    }
};