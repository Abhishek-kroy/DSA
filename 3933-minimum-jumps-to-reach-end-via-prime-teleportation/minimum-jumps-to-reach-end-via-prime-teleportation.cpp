class Solution {
public:
    int N=1000001;
    static int isprime[1000001];
    static int s;   
    void sieve(){
        if(s){
            return ;
        }

        s=1;   

        isprime[0]=-1;
        isprime[1]=-1;

        for(int i=2;i<N;i++){
            isprime[i]=i;
        }

        for(int i=2;i*i<=N;i++){
            if(isprime[i]==i){
                for(int j=i*i;j<N;j+=i){
                    if(isprime[j]==j){
                        isprime[j]=i;   
                    }
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {

        int n=nums.size();   

        sieve();

        unordered_map<int,unordered_set<int>> f;

        for(int i=0;i<n;i++){
            int val=nums[i];

            while(isprime[val]!=-1){
                f[isprime[val]].insert(i);     
                val=val/isprime[val];
            }
        }

        queue<int> q;
        q.push(0);

        vector<int> visited(n,0);
        visited[0]=1;

        unordered_set<int> used;   

        int l=0;

        while(!q.empty()){
            int sz=q.size();
            l++;

            while(sz--){
                int node=q.front();
                q.pop();

                if(node==n-1){
                    return l-1;   
                }

                if(node+1<n && !visited[node+1]){
                    q.push(node+1);
                    visited[node+1]=1;
                }       

                if(node-1>=0 && !visited[node-1]){
                    q.push(node-1);
                    visited[node-1]=1;
                }                       

                if(isprime[nums[node]]==nums[node]  && used.find(nums[node])==used.end()){
                    used.insert(nums[node]);   
                    for(auto ind:f[nums[node]]){
                        if(!visited[ind]){
                            q.push(ind);                                                        
                            visited[ind]=1;
                        }
                    }
                } 

            }
        }

        return -1; 

    }
};

int Solution::isprime[1000001];    

int Solution::s=0; 