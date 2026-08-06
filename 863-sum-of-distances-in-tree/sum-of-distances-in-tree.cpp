class Solution {
public:
    void dfs1(int node,int par,vector<int>& subtree,vector<vector<int>>& adj,vector<int>& ans,int d){
        ans[0]+=d;
        int sum=0;
        for(auto ch:adj[node]){
            if(ch==par){
                continue;
            }
            dfs1(ch,node,subtree,adj,ans,d+1);        
            subtree[node]+=subtree[ch];
        }

        subtree[node]+=1;
    }
    void dfs2(int node,int par,vector<int>& ans,vector<vector<int>>& adj,vector<int>& subtree){
        ans[node]=ans[par]-subtree[node]+(subtree[0]-subtree[node]);    

        for(auto ch:adj[node]){
            if(ch==par){
                continue;
            }
            dfs2(ch,node,ans,adj,subtree);
        }                

    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> subtree(n,0);
        vector<int> ans(n,0);

        dfs1(0,-1,subtree,adj,ans,0);

        for(auto ch:adj[0]){
            dfs2(ch,0,ans,adj,subtree);
        }   

        return ans;      
    }
};