class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();

        vector<vector<pair<int,int>>> adj(n);

        for(auto e:edges){
            int x=e[0];
            int y=e[1];
            int t=e[2];

            adj[x].push_back({y,t});
            adj[y].push_back({x,t});
        }

        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(maxTime+1,INT_MAX));

        pq.push({passingFees[0],{0,0}});
        dist[0][0]=passingFees[0];

        while(!pq.empty()){
            pair<int, pair<int,int>> v1=pq.top();          
            pq.pop();

            int cost=v1.first;
            int time=v1.second.first;
            int city=v1.second.second;          

            if(time>maxTime){
                continue;
            }

            if(dist[city][time]<cost){
                continue; 
            }

            if(city==n-1){
                return cost;
            }

            for(auto [v,t]:adj[city]){
                // int v=nei[0];   
                // int t=nei[1];                    

                if(time+t<=maxTime && dist[v][time+t]>cost+passingFees[v]){
                    dist[v][time+t]=cost+passingFees[v];        
                    pq.push({cost+passingFees[v],{time+t,v}});                                     
                }                                                                             
            }
        }


        return -1;    
    }
};