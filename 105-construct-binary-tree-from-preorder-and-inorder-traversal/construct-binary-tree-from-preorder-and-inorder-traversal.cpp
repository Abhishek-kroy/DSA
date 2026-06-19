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
    TreeNode* getans(vector<int>& preorder,vector<int>& inorder,int &i,int j,int k){
        if(j>k || i>=(int)preorder.size()){          
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[i]);
        i++;


        for(int l=j;l<=k;l++){
            if(inorder[l]==root->val){                       
                root->left=getans(preorder,inorder,i,j,l-1);
                root->right=getans(preorder,inorder,i,l+1,k);
            }
        }

        return root;             
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0; 
        return getans(preorder,inorder,i,0,(int)inorder.size()-1);        
    }
};