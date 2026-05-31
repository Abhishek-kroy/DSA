class Solution {
public:

    long long getans(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j){
        int n=grid.size();
        int m=grid[0].size();

        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]){
            return INT_MAX;
        }

        if(i==n-1 && j==m-1){
            return grid[i][j]; 
        }

        vis[i][j]=1; 

        long long w1=getans(grid,vis,i+1,j);
        long long w2=getans(grid,vis,i,j+1);
        long long w3=getans(grid,vis,i-1,j);
        long long w4=getans(grid,vis,i,j-1);

        int st=grid[i][j];

        vis[i][j]=0;    

        return st+min({w1,w2,w3,w4});  
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int> (m,INT_MAX));

        // return getans(grid,vis,0,0);

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=grid[0][0];

        while(!pq.empty()){
            auto [st,t]=pq.top();

            pq.pop();


            auto [i,j]=t;

            if(i==n-1 && j==m-1){
                return st;    
            }

            if(st>vis[i][j]){
                continue; 
            }


            if(i+1<n && vis[i+1][j]>grid[i+1][j]+st){     
                vis[i+1][j]=grid[i+1][j]+st;
                pq.push({vis[i+1][j],{i+1,j}});
            }
            if(i-1>=0 && vis[i-1][j]>grid[i-1][j]+st){
                vis[i-1][j]=grid[i-1][j]+st;
                pq.push({vis[i-1][j],{i-1,j}});
            }
            if(j+1<m && vis[i][j+1]>grid[i][j+1]+st){
                vis[i][j+1]=grid[i][j+1]+st;
                pq.push({vis[i][j+1],{i,j+1}});
            }
            if(j-1>=0 && vis[i][j-1]>grid[i][j-1]+st){
                vis[i][j-1]=grid[i][j-1]+st;
                pq.push({vis[i][j-1],{i,j-1}});    
            }




        }

        return 0; 

    }
};