class Solution {
private:
    void dij(unordered_map<int,vector<pair<int,int>>> &adj, int n, int k,vector<int>& dist){
        dist[k-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k-1});

        while(!pq.empty()){
            auto [distance,node]=pq.top();
            pq.pop();

            for(auto neigh:adj[node]){
                int nnode=neigh.first;
                int cost=neigh.second;

                if(distance+cost<dist[nnode]){
                    dist[nnode]=distance+cost;
                    pq.push({dist[nnode],nnode});
                }
            }
        }

        return ;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,INT_MAX);

        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto t:times){
            adj[t[0]-1].push_back({t[1]-1,t[2]});
        }
        dij(adj,n,k,dist);

        int ans=0;
        for(auto i:dist){
            ans=max(ans,i);
        }

        return ans==INT_MAX ? -1 : ans;
        

    }
};