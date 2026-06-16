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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(!root){
            return {};          
        }

       vector<vector<int>> ans;

       queue<TreeNode*> q;
       q.push(root);

       int l=0;

       while(!q.empty()){
        int sz=q.size();

        if(l%2==0){
            vector<int> res; 
            while(sz--){
                TreeNode* node=q.front();
                res.push_back(node->val);    

                q.pop();

                if(node->left){
                    q.push(node->left);
                }

                if(node->right)
                    q.push(node->right);


            }

            ans.push_back(res);         
        }
        else{
            vector<int> res;           

            while(sz--){
                TreeNode* node=q.front();
                res.push_back(node->val);    

                q.pop();

                if(node->left){
                    q.push(node->left);    
                }

                if(node->right)        
                    q.push(node->right);


            }

            reverse(res.begin(),res.end()); 

            ans.push_back(res);            


        }                
        l++;
       } 

       return ans;           
    }
};