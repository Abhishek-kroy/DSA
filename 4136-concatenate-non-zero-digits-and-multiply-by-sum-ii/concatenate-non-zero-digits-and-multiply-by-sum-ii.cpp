class Solution {
public:
    const int mod = 1e9+7; 

    int power(int x,int n){
        int res=1;

        while(n){
            if(n&1){
                res=(1LL*res*x)%mod;
            }

            x=(1LL*x*x)%mod;

            n=n>>1;
        }

        return res;            
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
       // 1 1 12 12 123 123 123 1234  

       int n=s.size();

       vector<int> pre1(n);
       vector<int> pre2(n);
       vector<int> pre3(n);

       pre1[0]=s[0]-'0';
       pre2[0]=s[0]-'0'; 

       pre3[0]=(s[0]=='0' ? 0:1); 

       for(int i=1;i<n;i++){
        int v=s[i]-'0';

        pre2[i]=(pre2[i-1]+v)%mod; 

        if(v!=0){
            pre1[i]=(1LL*pre1[i-1]*10+v)%mod;
            pre3[i]+=pre3[i-1]+1;
        }
        else{
            pre1[i]=pre1[i-1]; 
            pre3[i]+=pre3[i-1];
        }
       }

    //    for(int i=0;i<n;i++){
    //     cout<<pre1[i]<<" "<<pre2[i]<<endl;
    //    }

    //    cout<<endl;
    //    cout<<endl;

       vector<int> ans(queries.size());        

       int i=0;          

       for(auto q:queries){
        int l=q[0];
        int r=q[1];

        int v1=pre1[r];
        int v2=0;

        if(l>0){
            v2=(1LL*pre1[l-1]*(power(10,(pre3[r]-(l>0 ? pre3[l-1]:0))))%mod+mod)%mod;
        }

        // cout<<v1<<" "<<v2<<endl; 

        ans[i]=(1LL*(v1-v2+mod)%mod*(pre2[r]-(l>0 ? pre2[l-1] : 0)+mod)%mod)%mod;      

        i++; 
       }

       return ans; 
    }
};