class Solution {
public:
    int minJumps(vector<int>& arr) {
        queue<int> q;
        q.push(0); 

        int n=arr.size();   

        unordered_map<int,vector<int>> d;
        for(int i=0;i<n;i++){
            d[arr[i]].push_back(i);   
        }

        unordered_map<int,bool> check; 

        vector<bool> vis(n,false);
        vis[0]=true;   

        int l=0;

        while(!q.empty()){

            int size=q.size();
            l++;   

            while(size--){
                int ind=q.front();
                q.pop();

                if(ind==n-1){
                    return l-1;   
                }

                if(ind+1<n && !vis[ind+1]){
                    q.push(ind+1);
                    vis[ind+1]=true;
                }

                if(ind-1>=0 && !vis[ind-1]){
                    q.push(ind-1);
                    vis[ind-1]=true;
                }

                if(!check[arr[ind]]){
                    for(auto idx:d[arr[ind]]){
                        if(!vis[idx]){
                            q.push(idx);
                            vis[idx]=true;   
                        }
                    }
                }

                check[arr[ind]]=true;

            }

        }

        return -1;   
    }
};