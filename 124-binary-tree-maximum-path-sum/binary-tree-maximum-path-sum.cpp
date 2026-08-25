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
    int getans(TreeNode* root, int& ans){
        if(!root){
            return 0;
        }

        int l=getans(root->left,ans);
        int r=getans(root->right,ans);

        int w1=l+root->val+r;
        int w2=root->val+r;
        int w3=l+root->val;
        int w4=root->val;
        ans=max({ans,w1,w2,w3,w4});

        return max({w2,w3,w4});
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;    
        getans(root,ans);

        return ans;
    }
};