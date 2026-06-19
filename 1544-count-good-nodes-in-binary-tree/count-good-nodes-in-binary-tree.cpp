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
    int getans(TreeNode* root,int val){
        if(!root){
            return 0;
        }

        return (root->val>=val ? 1:0)+getans(root->left,max(val,root->val))+getans(root->right,max(val,root->val));        
    }
    int goodNodes(TreeNode* root) {            
        return getans(root, INT_MIN);   
    }
};