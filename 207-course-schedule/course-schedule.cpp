class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }

        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            cnt++;

            for(auto neigh:adj[node]){
                if(--indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        return cnt==numCourses;
    }
};