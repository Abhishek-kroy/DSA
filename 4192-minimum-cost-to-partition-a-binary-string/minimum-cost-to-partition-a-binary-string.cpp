class Solution {
public:
    long long getans(string& s, int encCost, int flatCost,int i,int j,vector<int>& pre) {
        if(i==j){
            int size=j-i+1;
            int cnt=i==0? pre[j]:pre[j]-pre[i-1];
            long long v=cnt==0? flatCost:1LL*size*cnt*encCost;      

            return v;      

        }
        int size=j-i+1;
        int cnt=i==0? pre[j]:pre[j]-pre[i-1];
        long long v=cnt==0? flatCost:1LL*size*cnt*encCost;    
        long long v2=LLONG_MAX;

        if(size%2==0){
            int mid=i+(j-i)/2;    
            v2=min(v2,1LL*getans(s,encCost,flatCost,i,mid,pre)+1LL*getans(s,encCost,flatCost,mid+1,j,pre));    
        }

        return min(v,v2);     
    }

    long long minCost(string s, int encCost, int flatCost) {
        int n=s.size();
        if(n%2){
            int size=n;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    cnt++;
                }
            }

            long long v=cnt==0? flatCost:1LL*size*cnt*encCost;  

            return v;    
        }

        vector<int> pre(n,0);
        if(s[0]=='1'){
            pre[0]=1;
        }
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+(s[i]=='1'? 1:0);    
        }

        return getans(s,encCost,flatCost,0,n-1,pre);    
    }
};