class Solution {
public:

    long long getans(int num,int cnt,int tight,int i,vector<vector<vector<long long>>> &dp){
        if(cnt==0){      
            return 1;
        }
        if(i<0){
            return 0;
        }

        if(dp[i][cnt][tight]!=-1){
            return dp[i][cnt][tight]; 
        }

        int bit=(num&(1<<i)) ? 1 : 0 ;      

        int limit = (tight==0 ? 1:bit);      

        long long ans=0;

        for(int b=0;b<=limit;b++){
            int ntight=( tight && b==limit ? true:false);  

            ans+=getans(num,cnt-b,ntight,i-1,dp);       
        }

        dp[i][cnt][tight]=ans;
        return dp[i][cnt][tight]    ;  

    }

    int countPrimeSetBits(int left, int right) {
        vector<int> cnt={2,3,5,7,11,13,17,19,23,27,29,31};   

        long long ans=0;


        for(auto p:cnt){
            vector<vector<vector<long long>>> dp1(32,vector<vector<long long>> (32,vector<long long>(2,-1)));
            vector<vector<vector<long long>>> dp2(32,vector<vector<long long>> (32,vector<long long>(2,-1)));
            ans+=getans(right,p,1,30,dp1);
            ans-=getans(left-1,p,1,30,dp2);                          
        }

        return ans; 
    }
};