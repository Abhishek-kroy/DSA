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
    void getans(TreeNode* root,vector<int>& ans){
        if(!root){
            return ;
        }

        getans(root->left,ans);

        ans.push_back(root->val);

        getans(root->right,ans); 
        
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        getans(root,ans);

        return ans;
    }
};