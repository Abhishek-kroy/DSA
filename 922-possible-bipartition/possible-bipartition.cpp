class Solution {
public:
    bool bfs(vector<vector<int>>& adj,int node,vector<int>& vis){
        vis[node]=1;

        int c=1; 

        queue<pair<int,int>> q;

        q.push({node,c});

        while(!q.empty()){
            auto [nod,col]=q.front();
            q.pop();

            for(auto nei:adj[nod]){
                if(!vis[nei]){
                    vis[nei]= col == 1 ? 2 : 1 ;
                    q.push({nei,vis[nei]});
                }
                else if(vis[nei]==col){
                    return false;
                }
            }                        
        }

        return true;        
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n+1);

        for(auto d:dislikes){
            adj[d[0]].push_back(d[1]);               
            adj[d[1]].push_back(d[0]);               
        }

        vector<int> vis(n+1,0);

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                bool v=bfs(adj,i,vis);

                if(!v){
                    return v;
                }
            }
        }

        return true; 
    }
};