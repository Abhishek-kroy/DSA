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
    void getans(TreeNode* root,int row,int col,map<int,map<int,vector<int>>>& f){
        if(!root){
            return ;
        }         

        f[col][row].push_back(root->val);

        getans(root->left,row+1,col-1,f);

        getans(root->right,row+1, col+1,f);

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> f;
        getans(root,0,0,f);

        vector<vector<int>> ans;            

        for(auto& p:f){

            vector<int> res;            

            for(auto& k:p.second){
                sort(k.second.begin(),k.second.end()); 

                for(auto v:k.second)
                    res.push_back(v);      
            }

            ans.push_back(res);            

        }

        return ans;
    }
};