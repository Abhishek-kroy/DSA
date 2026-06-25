class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adj(n);       

        for(auto p:prerequisites){
            adj[p[0]].push_back(p[1]);
        }                             

        vector<int> inorder(n,0);

        for(int i=0;i<n;i++){
            for(auto nei:adj[i]){
                inorder[nei]++;
            }
        }    

        queue<int> q;

        for(int i=0;i<n;i++){
            if(!inorder[i]){
                q.push(i);
            }
        }

        vector<vector<bool>> pre(n,vector<bool> (n,false));

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            for(auto nei:adj[node]){
                for(int i=0;i<n;i++){
                    if(pre[node][i])
                        pre[nei][i]=true;      
                }                         

                pre[nei][node]=true; 

                inorder[nei]--;

                if(!inorder[nei]){
                    q.push(nei);
                }       
            }
        }

        vector<bool> res;        

        for(auto q:queries){
            int u=q[0];
            int v=q[1];

            bool ans=pre[v][u]; 

            res.push_back(ans);
        }

        return res;        
    }
};