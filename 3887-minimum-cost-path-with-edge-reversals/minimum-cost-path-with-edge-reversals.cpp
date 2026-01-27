#define iii pair<int,int>
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> adjori;
        unordered_map<int,vector<pair<int,int>>> adjrev;
        for(auto e:edges){
            adjori[e[0]].push_back({e[1],e[2]});
            adjrev[e[1]].push_back({e[0],2*e[2]});          
        }

        // priority_queue<iii> pq;
        priority_queue<iii, vector<iii>, greater<iii>> pq;  

        pq.push({0,0});

        vector<int> dist(n,INT_MAX) ;    
        dist[0] = 0; 

        while(!pq.empty()){
            auto [di,node]=pq.top();
            pq.pop();



            // auto [node]=pa;  

            // if(node==n-1){
            //     return di;
            // }    

            for(auto [nei,cost]:adjori[node]){
                if(dist[nei]==INT_MAX || dist[nei]>di+cost){
                    pq.push({di+cost,nei}); 
                    dist[nei]=di+cost ;     
                }
            }

            // if(!ch){
                for(auto [nei,cost]:adjrev[node]){
                    if(dist[nei]==INT_MAX || dist[nei]>di+cost){  
                        pq.push({di+cost,nei});        
                        dist[nei]=di+cost  ;     
                    }
                }
            // }
        }

        int ans= min(dist[n-1],dist[n-1]) ;  

        return ans==INT_MAX ? -1 : ans ;       
    }
};