class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        set<pair<int,int>> s;

        for(auto c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
            s.insert({c[0],c[1]}); 
        }

        vector<int> vis(n,0);

        queue<int> q;

        q.push(0);

        vis[0]=1;

        int ans=0;  

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto nei:adj[node]){
                if(!vis[nei]){
                    vis[nei]=1;
                    q.push(nei);

                    if(s.find({nei,node})==s.end()){
                        ans++;          
                    }
                }
            }
        }

        return ans; 
    }
};