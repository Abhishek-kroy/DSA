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
    bool getans(TreeNode* root,long long l,long long r){
        if(!root){
            return true;         
        }

        if(root->val>l && root->val<r){
            return getans(root->left,l,root->val) && getans(root->right,root->val,r);
        }

        return false; 
    }
    bool isValidBST(TreeNode* root) {
        return getans(root,LLONG_MIN,LLONG_MAX);
    }
};