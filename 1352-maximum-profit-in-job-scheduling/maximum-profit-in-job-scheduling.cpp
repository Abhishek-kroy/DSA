class Solution {
public:
    int getvalue(vector<int>& dp,vector<int>& endTime,int i,int st){     
        int l=0;
        int r=i-1;        

        int ans=0; 

        while(l<=r){
            int mid=(l+r)/2;
            if(endTime[mid]>st){     
                r=mid-1;
            }
            else{
                ans=max(ans,dp[mid]);  
                l=mid+1;  
            }
        }

        return ans;
    } 

    static bool op(vector<int>& a,vector<int>& b){
        return a[1]<b[1];      
    } 

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();           
        vector<vector<int>> events(n);
        for(int i=0;i<n;i++){
            events[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(events.begin(),events.end(),op);    

        for(int i=0;i<n;i++){
            startTime[i]=events[i][0];
            endTime[i]=events[i][1];
            profit[i]=events[i][2];  
        }

        vector<int> dp(n,-1);

        dp[0]=profit[0];      

        // int ans=0;

        for(int i=1;i<n;i++){  
            // take and not take

            int w1=dp[i-1];
            int w2=profit[i]+getvalue(dp,endTime,i,startTime[i]);

            dp[i]=max(w1,w2); 
        }          

        return dp[n-1];
    }
};