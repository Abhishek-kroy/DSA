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
    TreeNode* st;
    int start1;
    unordered_map<TreeNode*,TreeNode*> par;
    void dfs(TreeNode* ch,TreeNode* parent){
        if(!ch){
            return ;
        }

        if(ch->val==start1){
            st=ch;    
        }

        par[ch]=parent;

        dfs(ch->left,ch);
        dfs(ch->right,ch);
    }
    int amountOfTime(TreeNode* root, int start) {
        start1=start;
        dfs(root,root);


        unordered_set<TreeNode*> vis;

        vis.insert(st);

        queue<TreeNode*> q;
        q.push(st);

        int l=0;

        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                auto node=q.front();

                q.pop();

                if(!node){
                    continue;        
                }

                auto node1=node->left;
                auto node2=node->right;
                auto node3=par[node];

                if(vis.find(node1)==vis.end()  && node1){
                    vis.insert(node1);
                    q.push(node1);
                }
                if(vis.find(node2)==vis.end()  && node2){
                    vis.insert(node2);
                    q.push(node2);
                }
                if(vis.find(node3)==vis.end() && node3){
                    vis.insert(node3);
                    q.push(node3);
                }
            }

            l++;
        }

        return l-1;      
    }
};