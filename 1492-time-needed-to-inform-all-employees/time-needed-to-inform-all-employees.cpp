class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(i==headID){
                continue;
            }
            adj[manager[i]].push_back(i);
        }

        queue<int> q;
        q.push(headID);

        vector<int> dist(n,0);
        dist[headID]=informTime[headID];

        int ans=dist[headID];

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            for(auto nei:adj[node]){
                ans=max(ans,dist[node]+informTime[nei]);
                dist[nei]=dist[node]+informTime[nei];                                      
                q.push(nei);
            }
        }

        return ans; 
    }
};