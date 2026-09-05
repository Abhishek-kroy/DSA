class Solution {
public:
    long long power(long long a,long long b){
        long long res=1;
        while(b>0){
            if(b&1){
                res=res*a;
                if(res>10000){
                    return res;
                }
            }

            a=a*a;
            if(a>10000){
                return a;
            }
            b=b>>1;
        }

        return res;
    }

    unordered_map<int,unordered_map<int,int>> dp;

    int getans(vector<vector<int>>& adj,int node,int par,int t,vector<int>& coins,int k){
        if(t>=20){
            return 0;
        }                 
        int val=1LL*coins[node]>>t;

        if(dp.find(node)!=dp.end() && dp[node].find(t)!=dp[node].end()){
            return dp[node][t];
        }

        int w1=val-k;
        for(auto ch:adj[node]){
            if(ch!=par){
                w1+=getans(adj,ch,node,t,coins,k);
            }
        }

        int w2=val/2;
        for(auto ch:adj[node]){
            if(ch!=par){
                w2+=getans(adj,ch,node,t+1,coins,k);
            }
        }

        return dp[node][t]=max(w1,w2);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n=edges.size()+1;

        vector<vector<int>> adj(n);

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return getans(adj,0,-1,0,coins,k);
    }
};