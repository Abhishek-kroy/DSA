class Solution {
public:
    vector<vector<int>> adj;
    void geth(int node,vector<int>& h,vector<int>& d,int depth){
        d[node]=depth;
        for(auto ch:adj[node]){
            geth(ch,h,d,depth+1);
            h[node]=max(h[node],h[ch]);
        }
        h[node]+=1;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=nums.size();
        adj.resize(n);

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);                        
        }
        vector<int> h(n,0);
        vector<int> d(n,0);
        geth(0,h,d,1);

        int rooth=h[0];

        // cout<<"rooth "<<rooth<<endl;
        // cout<<endl;

        queue<int> q;
        q.push(0);

        vector<int> vis(n,0);
        vis[0]=1;

        long long ans=0;

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            ans+=(1LL*nums[node]*1LL*(rooth-d[node]+1));

            // cout<<"node "<<node<<endl;
            // cout<<"depth "<<d[node]<<endl;
            // cout<<"value "<<nums[node]*(rooth-d[node]+1)<<endl;        

            for(auto ch:adj[node]){
                if(!vis[ch]){
                    vis[ch]=1;
                    q.push(ch);
                }
            }
        }

        return ans;

    }
};