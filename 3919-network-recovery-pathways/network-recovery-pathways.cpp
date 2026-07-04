class Solution {
public:

    bool check(vector<vector<pair<int,int>>>& adj,int mid,long long k,int n){
        vector<int> ind(n,0);

        for(int i=0;i<n;i++){
            for(auto [nei,wt]:adj[i]){
                ind[nei]++;
            }
        }

        queue<int> q;

        vector<long long> dis(n,1e16);      
        // vector<long long> vis(n,0);
        
        dis[0]=0;

        for(int i=0;i<n;i++){
            if(!ind[i]){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto node=q.front();          
            q.pop();

            // long long d=dis[node]; 
            // int hasz=vis[node]; 

            for(auto [nei,wt]:adj[node]){
                ind[nei]--;

                if(wt>=mid){
                    // vis[nei]=1;
                    dis[nei]=min(dis[nei],dis[node]+1LL*wt); 
                }
                // if(hasz || node==0){
                // }    

                if(!ind[nei]){
                    q.push(nei); 
                }
            }
        }



        return dis[n-1]<=k;        
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();

        vector<vector<pair<int,int>>> adj(n);


        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];

            if(online[u] && online[v]){
                adj[u].push_back({v,w});

                mini=min(mini,w);
                maxi=max(maxi,w);
            }
        }

        int l=mini;
        int r=maxi;          

        int ans=-1; 

        while(l<=r){
            int mid=l+(r-l)/2;

            if(check(adj,mid,k,n)){
                ans=mid; 
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        return ans;             
    }
};