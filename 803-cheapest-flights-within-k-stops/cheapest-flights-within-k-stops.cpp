#define dsn pair<int,pair<int,int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<dsn,vector<dsn>,greater<dsn>> pq;
        k+=1;

        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto v:flights){
            adj[v[0]].push_back({v[1],v[2]});
        }

        pq.push({0,{0,src}});

        vector<vector<int>> dist(n,vector<int> (k+2,INT_MAX));
        for(int j=0;j<=k;j++){
            dist[src][j]=0;
        }

        while(!pq.empty()){
            auto [distance,l]=pq.top();
            pq.pop();

            auto [stop,node]=l;

            if(node==dst){
                return distance;
            }

            if(stop>=k){
                continue ;
            }

            for(auto neigh:adj[node]){
                int nnode=neigh.first;
                int cost=neigh.second;

                if(distance+cost<dist[nnode][stop]){
                    dist[nnode][stop]=distance+cost;
                    pq.push({dist[nnode][stop],{stop+1,nnode}});
                }
            }

        }

        return -1;
    }
};

