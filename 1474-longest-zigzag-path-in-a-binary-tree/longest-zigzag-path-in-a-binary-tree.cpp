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
    pair<int,int> getans(TreeNode* root,int& ans){
        if(!root){
            return {0,0};
        }

        auto [l1,r1]=getans(root->left,ans);
        auto [l2,r2]=getans(root->right,ans);    

        int l=1+r1;
        int r=1+l2;

        ans=max(ans,max(l,r)); 

        return {l,r};
    }

    int longestZigZag(TreeNode* root) {

        int ans=0;

        getans(root,ans);

        return ans-1;        
    }
};