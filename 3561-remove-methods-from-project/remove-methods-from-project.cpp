class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto v:invocations){
            adj[v[0]].push_back(v[1]);
        }

        queue<int> q;
        vector<int> vis(n,0);

        q.push(k);
        vis[k]=1;

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            for(auto nei:adj[node]){
                if(!vis[nei]){
                    vis[nei]=1;
                    q.push(nei);
                }
            }
        }

        
        for(auto v:invocations){
            int u=v[0];
            int d=v[1];

            if(!vis[u]  && vis[d]){
                vector<int> res;
                for(int i=0;i<n;i++){
                    res.push_back(i);
                }
                return res;
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                res.push_back(i);
            }
        }

        return res;
    }
};