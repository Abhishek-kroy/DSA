class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);

        for(auto r:relations){
            adj[r[0]-1].push_back(r[1]-1);
        }

        vector<int> inorder(n,0);

        vector<int> t(n,0); 

        for(int i=0;i<n;i++){
            for(auto nei:adj[i]){
                inorder[nei]++;
            }
        }

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            if(!inorder[i]){
                q.push({i,time[i]});        
            }
        }

        int ans=0; 

        while(!q.empty()){
            auto [node,tt]=q.front();
            q.pop();

            ans=max(ans,tt);        

            for(auto nei:adj[node]){
                inorder[nei]--;


                t[nei]=max(t[nei],tt);                


                if(!inorder[nei]){

                    q.push({nei,t[nei]+time[nei]});  
                }
            }
        }

        return ans; 
    }
};