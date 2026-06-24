class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(n);

        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
        } 

        vector<int> inorder(n);

        for(int i=0;i<n;i++){
            for(auto nei:adj[i]){
                inorder[nei]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(!inorder[i]){
                q.push(i);
            }
        }

        vector<int> ans; 

        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans.push_back(node);

            for(auto nei:adj[node]){
                inorder[nei]--;

                if(!inorder[nei]){
                    q.push(nei);
                }
            }
        }

        vector<int> v;

        return ans.size()==n ? ans: v ;                     
    }
};