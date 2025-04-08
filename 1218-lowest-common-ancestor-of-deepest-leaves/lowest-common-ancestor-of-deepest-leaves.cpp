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
    pair<TreeNode*,int> getans(TreeNode* root,int d){
        if(!root){
            return {NULL,d};
        }

        auto [l,dl]=getans(root->left,d+1);
        auto [r,dr]=getans(root->right,d+1);

        if(dl==dr){
            return {root,dl};
        }

        if(dl>dr){
            return {l,dl};
        }
        return {r,dr};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return getans(root,0).first;
    }
};