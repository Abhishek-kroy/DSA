class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);          

        for(auto t:times){
            adj[t[0]].push_back({t[1],t[2]});            
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 
        vector<int> dis(n+1,INT_MAX);
        pq.push({0,k});
        dis[k]=0; 



        while(!pq.empty()){
            auto [dist,node]=pq.top();

            pq.pop();

            if(dis[node]<dist){
                continue; 
            }

            for(auto [nei,wt]:adj[node]){
                if(dis[nei]>dis[node]+wt){
                    dis[nei]=dis[node]+wt;

                    pq.push({dis[nei],nei});
                }
            }
        } 

        int ans=0;

        for(int i=1;i<n+1;i++){
            ans=max(ans,dis[i]);
        }

        if(ans==INT_MAX){
            return -1; 
        }

        return ans;          
    }
};