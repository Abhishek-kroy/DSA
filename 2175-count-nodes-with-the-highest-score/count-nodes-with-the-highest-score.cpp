class Solution {
public:
    int getsize(unordered_map<int,vector<int>>& adj,int node,vector<int>& size){  
        int sz=0;

        for(auto ch:adj[node]){
            sz+=getsize(adj,ch,size);
        }

        size[node]=sz+1;

        return size[node];   
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        unordered_map<int,vector<int>> adj;
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i); 
        }

        vector<int> size(n);
        getsize(adj,0,size);   

        long long ans=0; 
        unordered_map<long long,int> f;  

        for(int i=0;i<n;i++){
            long long val = max(1,(n-size[i]));    
            for(auto ch:adj[i]){
                val=val*size[ch];
            }
            f[val]++;
            ans=max(ans,val);
        } 

        return f[ans]; 
    }
};