class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            q.push({i,1<<i});
        }

        int l=0;
        vector<vector<int>> vis(n,vector<int>((1<<n)+1,0));           

        while(!q.empty()){
            int sz=q.size();    

            while(sz--){
                auto [node,mask]=q.front();
                q.pop();

                if(mask==((1<<n)-1)){
                    return l;
                }

                for(auto nei:graph[node]){
                    int nmask=mask|(1<<nei);
                    if(!vis[nei][nmask]){
                        vis[nei][nmask]=1;                        
                        q.push({nei,nmask});
                    }
                }
            }
            l++;
        }

        return -1;  
    }
};