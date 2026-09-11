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

        auto [lsum,lcnt]=getans(root->left,ans);
        auto [rsum,rcnt]=getans(root->right,ans);

        int avg=(lsum+rsum+root->val)/(lcnt+rcnt+1);

        ans+=(root->val==avg);        

        return {lsum+rsum+root->val,lcnt+rcnt+1};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        getans(root,ans);                

        return ans;    
    }
};