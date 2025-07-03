class Solution {
public:
    int getans(int pos,vector<int> &digits,int tight,int prevone,vector<vector<vector<int>>> &dp){
        if(pos==digits.size()){
            return 1;
        }


        if(dp[pos][tight][prevone]!=-1){
            return dp[pos][tight][prevone];
        }

        int limit;
        if(tight){
            limit=digits[pos];
        }
        else{
            limit=1;
        }

        // if(prevone){
        //     if(limit==1){
        //         limit=0;
        //     }
        // }

        // 1 1 0

        int w=0;

        for(int i=0;i<=limit;i++){
            if(prevone && i==1) continue;
            bool newtight=(tight&&(i==limit));
            bool newprevone=(i==1);
            w+=getans(pos+1,digits,newtight,newprevone,dp);
        }

        return dp[pos][tight][prevone]=w;
    }

    vector<int> getdigit(int n){
        vector<int> d;
        while(n>0){
            int bit=n&1;
            d.push_back(bit);
            n=n>>1;
        }
        return d;
    }

    int findIntegers(int n) {

        vector<int> digits=getdigit(n);
        reverse(digits.begin(),digits.end());
        vector<vector<vector<int>>> dp(digits.size(),vector<vector<int>> (2,vector<int>(2,-1)));
        return getans(0,digits,1,0,dp);
    }
};