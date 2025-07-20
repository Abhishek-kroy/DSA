class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int getans(vector<vector<int>>& intervals,int i){
        int l=0;
        int r=i-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(intervals[mid][1]<=intervals[i][0]){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        vector<int> dp(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int j=getans(intervals,i);
            int w1=1;
            if(j!=-1){
                w1+=dp[j];
            }
            if(i>0)
                dp[i]=max(dp[i-1],w1);
            else{
                dp[i]=w1;     
            }

            ans=max(ans,dp[i]);
        }

        return n-dp[n-1];
    }
};