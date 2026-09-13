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
    TreeNode* getans(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root){
            return NULL;
        }

        if(root->val==p->val || root->val==q->val){
            return root;
        }

        TreeNode* l=getans(root->left,p,q);
        TreeNode* r=getans(root->right,p,q);

        if(l && r){
            return root;
        }
        if(l){
            return l;        
        }

        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return getans(root,p,q);
    }
};