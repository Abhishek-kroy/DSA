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
    TreeNode* getans(vector<int>& inorder,vector<int>& postorder,int i,int j,int& k){
        if(k<0){
            return NULL;
        }

        if(i>j){
            return NULL;
        }

        TreeNode* root=new  TreeNode(postorder[k]);    

        k--;  

        for(int l=i;l<=j;l++){
             if(inorder[l]==root->val){
                root->right=getans(inorder,postorder,l+1,j,k);
                root->left=getans(inorder,postorder,i,l-1,k);
             }
        }

        return root;          
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int k=(int)postorder.size()-1;          
        return getans(inorder,postorder,0,(int)inorder.size()-1,k);                  
    }
};