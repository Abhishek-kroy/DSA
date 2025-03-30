class Solution {
    private:
    void bfs(int node,vector<vector<int>> & adj,vector<int> &visited){
        queue<int> q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            int nod=q.front();
            q.pop();
            for(int i=0;i<adj[nod].size();i++){
                if(adj[nod][i] && !visited[i]){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }

        return ;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int province=0;
        int vertices=isConnected.size();
        vector<int> visited(vertices,0);
        for(int i=0;i<vertices;i++){
            if(!visited[i]){
                province++;
                bfs(i,isConnected,visited);
            }
        }

        return province;
    }
};