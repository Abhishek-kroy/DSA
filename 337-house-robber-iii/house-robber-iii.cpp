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
    map<pair<TreeNode*,int>,int> f; 
    int getans(TreeNode* root,int rb){
        if(!root){
            return 0;
        }

        if(f.find({root,rb})!=f.end()){
            return f[{root,rb}];
        }                

        if(rb){
            int w1=root->val+getans(root->left,0)+getans(root->right,0);
            int w2=0+getans(root->left,rb)+getans(root->right,rb);

            return f[{root,rb}]=max(w1,w2);
        }

        return f[{root,rb}]=getans(root->left,1)+getans(root->right,1);      
    }

    int rob(TreeNode* root) {
        return getans(root,1);
    }
};