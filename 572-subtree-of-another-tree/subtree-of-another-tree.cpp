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
    bool issame(TreeNode* root,TreeNode* subRoot){
        if(!root && !subRoot){
            return true;
        }               

        if(!root || !subRoot){
            return false;
        } 

        return root->val==subRoot->val && issame(root->left,subRoot->left) && issame(root->right,subRoot->right); 
    }

    bool getans(TreeNode* root,TreeNode* subRoot){
        if(!root && !subRoot){
            return true;
        }

        if(!root || !subRoot){
            return false; 
        }

        bool w1=issame(root,subRoot);

        if(w1){
            return w1; 
        }

        return getans(root->left,subRoot) || getans(root->right,subRoot); 
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return getans(root,subRoot);
    }
};