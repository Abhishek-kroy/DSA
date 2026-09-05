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
    vector<long long> getans(TreeNode* root,long long& ans){
        if(!root){
            return {INT_MAX,INT_MIN,0};
        }

        auto l1=getans(root->left,ans);

        auto l2=getans(root->right,ans);            

        long long sum=INT_MIN;

        if(l1[2]!=INT_MIN && l2[2]!=INT_MIN && root->val>l1[1] && root->val<l2[0]){
            ans=max(ans,1LL*l1[2]+root->val+l2[2]);        
            sum=1LL*l1[2]+l2[2]+root->val;            
        }

        int left= l1[1]==INT_MIN ? root->val:l1[0];
        int right=l2[0]==INT_MAX ? root->val:l2[1];

        return {left,right,sum};        
    }

    int maxSumBST(TreeNode* root) {
        long long ans=0;
        getans(root,ans);
        return ans;
    }
};