class Solution {
public:
    int getans(int n,vector<vector<int>>& adj, vector<int>& vis,int node,int dist){
        vis[node]=dist;

        int ans=0;

        for(auto nei:adj[node]){        
            if(vis[nei]==1){
                continue; 
            }

            else if(vis[nei]>=2){
                int val = abs ( vis[nei]-dist);
                ans=max(ans,val+1);
            }

            else{
                ans=max(ans,getans(n,adj,vis,nei,dist+1));                                
            }
        }
        vis[node]=1;

        return ans; 
    }

    int longestCycle(vector<int>& edges) {

        int n=edges.size();

        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);        
            }
        }

        int ans=0;      

        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans=max(ans,getans(n,adj,vis,i,2));        
            }                        
        }

        return ans==0 ? -1 : ans;        
    }
};