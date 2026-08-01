class Solution {
public:
    int ans=0; 
    pair<int,int> getans(string& num,int i,int tight,vector<vector<pair<int,int>>>& dp,vector<vector<int>>& visited){
        int n=num.size();

        if(i>=n){
            return {0,1};
        }

        if(visited[i][tight]!=-1){
            return dp[i][tight];
        }

        int limit = tight ? num[i]-'0':9;

        int cnt=0;        

        int totalnum=0;

        for(int v=0;v<=limit;v++){
            int ntight=tight && (v==limit);
            auto [cnt1,nums]=getans(num,i+1,ntight,dp,visited);                

            totalnum+=nums;

            if(v==1){
                cnt+=(nums)+cnt1;
            }
            else{
                cnt+=(cnt1);
            }
        }

        visited[i][tight]=1;        

        dp[i][tight]={cnt,totalnum};

        return {cnt,totalnum};    
    }
    int countDigitOne(int n) {
        string num=to_string(n);

        // getans(num,0,true).first;              

        vector<vector<pair<int,int>>> dp((int)num.size(),vector<pair<int,int>> (2));                
        vector<vector<int>> visited((int)num.size(),vector<int> (2,-1))            ; 


        return getans(num,0,1,dp,visited).first;        
    }
};