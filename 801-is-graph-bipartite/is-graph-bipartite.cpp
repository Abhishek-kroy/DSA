class Solution {
public:
    bool dfs(vector<vector<int>> &graph,int color,int node,vector<int> &visited){
        visited[node]=color;

        for(auto neigh:graph[node]){
            if(visited[neigh]==-1){
                if(!dfs(graph,1-color,neigh,visited))
                    return false;
            }
            else if(visited[neigh]==color){
                return false;
            }
        }

        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);

        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(!dfs(graph,0,i,visited)){
                    return false;
                }
            }
        }

        return true;


    }
};