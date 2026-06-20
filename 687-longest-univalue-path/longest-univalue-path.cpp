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
            return {1001,0};
        }                   

        auto [v1,f1]=getans(root->left,ans);             
        auto [v2,f2]=getans(root->right,ans);             

        int val=root->val;

        if(val==v1 && val==v2){
            ans=max(ans,f1+1+f2);        

            return {val,1+max(f1,f2)};
        }
        else if(val==v1){
            ans=max(ans,f1+1);

            return {val,1+f1};
        }
        else if(val==v2){
            ans=max(ans,1+f2);

            return {val,1+f2};
        }

        ans=max(ans,1);

        return {val,1};        
    }

    int longestUnivaluePath(TreeNode* root) {
        int ans=0;

        getans(root,ans);

        if(ans==0){
            return ans; 
        }

        return ans-1;                         
    }
};