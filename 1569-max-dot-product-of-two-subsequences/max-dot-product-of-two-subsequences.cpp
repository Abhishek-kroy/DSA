class Solution {
public:
    int getans(vector<int>& nums1, vector<int>& nums2,int i1,int i2,vector<vector<int>>& dp){
        if(i1<0 || i2<0)    return 0;

        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }

        // take the element
        int w1=nums1[i1]*nums2[i2]+getans(nums1,nums2,i1-1,i2-1,dp);
        int w2=getans(nums1,nums2,i1-1,i2,dp);
        int w3=getans(nums1,nums2,i1,i2-1,dp);       

        return dp[i1][i2]=max({w1,w2,w3});  
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        vector<vector<int>> dp(n1,vector<int> (n2,-1));  

        int ans=INT_MIN;

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                ans=max(ans,nums1[i]*nums2[j]);
            }
        }

        if(ans<0)   return ans;


        return getans(nums1,nums2,n1-1,n2-1,dp);              

        
    }
};