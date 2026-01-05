class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        vector<int> oneleft(n,0);
        oneleft[0]=(s[0]=='1' ? 1:0);
        for(int i=1;i<n;i++){
            oneleft[i]=oneleft[i-1]+(s[i]=='1'? 1:0);
        }

        vector<int> zeroright(n,0);
        zeroright[n-1]=(s[n-1]=='0' ? 1:0);   
        for(int i=n-2;i>=0;i--){      
            zeroright[i]=zeroright[i+1]+(s[i]=='0' ? 1:0);  
        }

        int ans=zeroright[0];
        for(int i=0;i<n;i++){
            ans=min(ans,oneleft[i] + (i<(n-1) ? zeroright[i+1] : 0)) ;      

        }

        return ans;     
    }
};