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
    int ans=0;
        int res=-1; 

    void getans(TreeNode* root,int k){
        if(!root){
            return ;
        }

        getans(root->left,k);

        ans++;

        if(ans==k){
            res=root->val;
        }

        getans(root->right,k);        
    }
    int kthSmallest(TreeNode* root, int k) {
        getans(root,k);        

        return res;        
    }
};