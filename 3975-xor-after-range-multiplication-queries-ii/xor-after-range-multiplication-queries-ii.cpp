class Solution {
public:
    int power(int a,int b){
        int mod=(int)1e9+7;   
        int res=1;
        while(b){
            if(b&1){
                res=(1LL*res*a)%mod;
            }
            a=(1LL*a*a)%mod;   
            b=b>>1;
        }

        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod=(int)1e9+7;   

        int n=nums.size();
        int rootn=pow(n,0.5);

        vector<vector<vector<int>>> v(rootn+1);

        for(auto q:queries){
            if(q[2]>rootn){
                for(int i=q[0];i<=q[1];i+=q[2]){
                    nums[i]=(1LL*nums[i]*q[3])%mod;
                }
            }
            else{
                v[q[2]].push_back(q);
            }
        }

        for(int j=1;j<=rootn;j++){
            if(v[j].size()){
                for(int i=0;i<j;i++){
                    vector<int> t(n/j+2,1);
                    for(auto q:v[j]){
                        if(q[0]%j==i){
                            int st=q[0]/j;
                            int end=st+(q[1]-q[0])/j;   
                            t[st]=(1LL*t[st]*q[3])%mod;
                            t[end+1]=(1LL*t[end+1]*power(q[3],mod-2))%mod;   
                        }
                    }

                    for(int l=0;l<t.size();l++){
                        if(l) t[l] = (1LL * t[l] * t[l-1]) % mod;   
                        int idx=l*j+i;   
                        if(idx<n){
                            nums[idx]=(1LL*nums[idx]*t[l])%mod;
                        }
                    }
                }
            }
        } 

        int ans=0;

        for(int i=0;i<n;i++){
            ans=ans^nums[i];
        }

        return ans; 
    }
};