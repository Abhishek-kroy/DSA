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
    int ans=1;
    int getans(TreeNode* root){
        if(!root){
            return 0;
        }

        int l=getans(root->left);   
        int r=getans(root->right);

        if(abs(l-r)>1){
            ans=0;
        }

        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        int h=getans(root);   
        return ans;
    }
};