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
    vector<int> getans(TreeNode* root,int& ans){
        if(!root){
            return {INT_MAX,INT_MIN,0};                      
        }

        auto v=getans(root->left,ans);        
        int l1=v[0];
        int r1=v[1];
        int s1=v[2];

        auto v2=getans(root->right,ans);                 
        int l2=v2[0];
        int r2=v2[1];
        int s2=v2[2];

        if(root->val>r1 && root->val<l2){
            ans=max(ans,s1+root->val+s2);          

            return {min(l1,root->val),max(root->val,r2),s1+root->val+s2};          
        }

        return {INT_MIN,INT_MAX,INT_MIN};           

    }
    int maxSumBST(TreeNode* root) {
        if(!root){
            return 0; 
        }

        int ans=0;

        auto v=getans(root,ans);       

        return ans; 
    }
};