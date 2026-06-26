class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            for(auto v:graph[i]){
                adj[v].push_back(i);
            }
        }        

        vector<int> inorder(n,0);

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
            auto node=q.front();
            q.pop();

            ans.push_back(node);

            for(auto nei:adj[node]){

                inorder[nei]--; 

                if(!inorder[nei]){
                    q.push(nei);
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;        
    }
};