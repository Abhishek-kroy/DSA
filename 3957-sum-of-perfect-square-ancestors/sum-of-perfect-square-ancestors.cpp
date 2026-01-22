class Solution {
public:
    static vector<int> pr;
    static void process(){  

        if(pr.size()!=0){
            return ; 
        }
        int n=1e5+2;
        pr.resize(n+1,-1);   
  
        pr[0]=0;
        pr[1]=0;

        for(int i=2;i*i<=n;i++){
            if(pr[i]==-1){
                pr[i]=i;
                for(int j=i*i;j<=n;j+=i){
                    if(pr[j]==-1)
                        pr[j]=i;
                }
            }
        }

        for(int i=2;i<=n;i++){
            if(pr[i]==-1)
                pr[i]=i;   
        }

    } 

    long long dfs(int node,vector<int>& visited,unordered_map<int,vector<int>> &adj,vector<int>& fact,unordered_map<int,long long>& ft){  
        visited[node]=1;



        long long w=ft[fact[node]];  

        ft[fact[node]]++;


        for(auto nei:adj[node]){
            if(!visited[nei]){
                w+=dfs(nei,visited,adj,fact,ft);   
            }
        }

        ft[fact[node]]--    ;  

        return w;
    }

    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        process();
        vector<int> fact(n,1);  
        for(int i=0;i<n;i++){
            int val=nums[i];
            int value=1;
            while(val>1){
                int f=pr[val];
                int cnt=0; 
                while((val%f)==0){
                    val/=f;
                    cnt=(cnt+1)%2;
                }

                if(cnt){
                    value=value*f;
                }
            }
            fact[i]=value;
        }

        unordered_map<int,vector<int>> adj;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);    
        }

        vector<int> visited(n,0); 
        unordered_map<int,long long> ft;  

        return dfs(0,visited,adj,fact,ft);   
    }
};

vector<int> Solution::pr;              