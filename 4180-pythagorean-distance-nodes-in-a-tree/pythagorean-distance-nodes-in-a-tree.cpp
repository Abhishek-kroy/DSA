#define ii pair<int,int>
class Solution {
public:
    vector<int> get(int n,unordered_map<int,vector<int>> &adj,int node){
        vector<int> dist(n,INT_MAX);
        dist[node]=0;

        priority_queue<ii,vector<ii>,greater<ii>> pq;
        pq.push({0,node});
        dist[node]=0;    

        while(!pq.empty()){
            auto [di,nod]=pq.top();
            pq.pop();

            for(auto nei:adj[nod]){
                if(dist[nei]==INT_MAX || dist[nei]>di+1){
                    pq.push({di+1,nei});
                    dist[nei]=di+1;  
                }
            }
        }

        return dist;  
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        unordered_map<int,vector<int>> adj  ; 

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dx=get(n,adj,x);
        vector<int> dy=get(n,adj,y);
        vector<int> dz=get(n,adj,z); 

        long long count=0;
        for(int i=0;i<n;i++){
            // if(i==x || i==y || i==z){
            //     continue;
            // }
            // else{
                vector<int> d={dx[i],dy[i],dz[i]};
                sort(d.begin(),d.end());  

                if(1LL*d[0]*d[0]+1LL*d[1]*d[1]==1LL*d[2]*d[2]){  
                    count++;   
                }                      
            // }   
        }

        return count ; 
    }
};