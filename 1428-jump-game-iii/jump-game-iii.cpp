class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);

        int n=arr.size();

        vector<bool> vis(n,false);
        vis[start]=true;


        while(!q.empty()){
            int node=q.front();
            q.pop(); 

            if(arr[node]==0){
                return true;
            }

            if(node+arr[node]<n && !vis[node+arr[node]]){
                vis[node+arr[node]]=true;
                q.push(node+arr[node]);
            }

            if(node-arr[node]>=0 && !vis[node-arr[node]]){
                vis[node-arr[node]]=true;
                q.push(node-arr[node]);
            }
        }

        return false;   
    }
};