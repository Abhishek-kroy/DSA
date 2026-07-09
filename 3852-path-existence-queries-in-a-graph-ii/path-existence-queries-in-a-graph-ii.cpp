class Solution {
public:
    int getupr(vector<vector<int>>& nums,int v){
        int n=nums.size();

        int l=0;          
        int r=n-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(nums[mid][0]<=v){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        return l;        
    }
    vector<int> pathExistenceQueries(int n, vector<int>& num, int maxDiff, vector<vector<int>>& queries) {
        vector<vector<int>> nums(n);


        for(int i=0;i<n;i++){
            nums[i]={num[i],i};
        }

        sort(nums.begin(),nums.end());

        vector<int> cmp(n);          

        int c=0; 

        for(int i=0;i<n;i++){
            cmp[i]=c;
            int j=i+1;
            while(j<n && nums[j][0]-nums[j-1][0]<=maxDiff){
                cmp[j]=c;
                j++;          
            }
            c++;

            i=j-1;          
        }

        vector<int> jump(n);

        for(int i=0;i<n;i++){
            int j=getupr(nums,nums[i][0]+maxDiff);    
            jump[i]=j-1;                        
        }

        unordered_map<int,int> f;

        for(int i=0;i<n;i++){
            f[nums[i][1]]=i; 
        }

        vector<vector<int>> v(n,vector<int> (log2(n)+1));   

        for(int i=0;i<n;i++){
            v[i][0]=jump[i];            
        }

        for(int k=1;k<=log2(n);k++){
            for(int i=0;i<n;i++){
                v[i][k]=v[v[i][k-1]][k-1];      
            }                        
        }

        vector<int> ans(queries.size());

        int i=0;      

        for(auto q:queries){
            int u=f[q[0]];
            int t=f[q[1]];

            if(cmp[u]!=cmp[t]){
                ans[i]=-1;

                i++;          
                continue; 
            }

            if(u==t){
                ans[i]=0;
                i++;

                continue;          
            }

            if(t<u){          
                swap(u,t);           
            }

            int cnt=0; 

            for(int k=log2(n);k>=0;k--){
                if(v[u][k]<t){          

                    cnt+=(1<<k); 
                    u=v[u][k]; 
                }
            }

            ans[i]=cnt+1;           
            i++;
        }

        return ans;           
    }
};