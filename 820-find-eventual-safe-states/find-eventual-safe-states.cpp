class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<graph.size();i++){
            vector<int> neigh=graph[i];

            for(auto nei:neigh){
                adj[nei].push_back(i);
            }
        }


        vector<int> indegree(graph.size(),0);

        for(int i=0;i<graph.size();i++){
            for(auto neigh:adj[i]){
                indegree[neigh]++;
            }
        }

        queue<int> q;

        for(int i=0;i<indegree.size();i++){
            if(!indegree[i]){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans.push_back(node);

            for(auto neigh:adj[node]){
                if(--indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};