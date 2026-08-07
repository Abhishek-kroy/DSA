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
        auto [l,cntl]=getans(root->left,ans);
        auto [r,cntr]=getans(root->right,ans);

        int tnode=cntl+cntr+1;
        int totalcoin=l+r+root->val;    

        ans+=abs(totalcoin-tnode);

        return {totalcoin,cntl+1+cntr};
    }
    int distributeCoins(TreeNode* root) {
        int ans=0;
        getans(root,ans);
        return ans;        
    }
};