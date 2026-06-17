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
    int getans(TreeNode* root,int& ans){            
        if(!root){
            return 0;
        }

        int w1=getans(root->left,ans);

        int w2=getans(root->right,ans);

        ans=max(ans,w1+root->val+w2);                          

        return max({0,w1+root->val,w2+root->val});
    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;

        getans(root,ans);

        return ans; 
    }
};