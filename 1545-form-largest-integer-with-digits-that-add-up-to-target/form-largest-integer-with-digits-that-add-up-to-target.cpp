class Solution {
public:
    string dp[5001];
    string getans(vector<int>& cost, int target){
        if(target==0){
            return "";
        }

        if(dp[target]!="-"){
            return dp[target];
        }

        string ans="0";

        for(int i=0;i<9;i++){
            if(cost[i]<=target){
                string r=getans(cost,target-cost[i]);
                if(r!="0"){
                    string w1=to_string(i+1)+r;
                    if(w1.size()>ans.size()){
                        ans=w1;
                    }
                    else if(w1.size()==ans.size()){
                        ans=max(ans,w1);   
                    }
                }

            }
        }
        
        dp[target]=ans;   

        return ans;   
    }

    string largestNumber(vector<int>& cost, int target) {
        for(int i=1;i<5001;i++){
            dp[i]="-";
        }

        dp[0]="";   

        return getans(cost,target);
    }
};