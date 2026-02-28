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
    bool getans(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return false;
        }

        int cnt=0;

        if(root==p || root==q){
            cnt++;
        }

        cnt=(getans(root->left,p,q)? cnt+1:cnt);
        cnt=(getans(root->right,p,q)? cnt+1:cnt);

        if(cnt==2 && !ans){
            ans=root;
        }

        return cnt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        getans(root,p,q);     
        return ans;
    }
};