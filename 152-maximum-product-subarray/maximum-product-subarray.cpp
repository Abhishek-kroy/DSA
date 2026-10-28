class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;

        int n=nums.size();

        int pre=1;
        int suf=1;

        for(int i=0;i<n;i++){
            pre=pre*nums[i];
            suf=suf*nums[n-1-i];

            ans=max(ans,max(pre,suf));

            if(pre==0){
                pre=1;
            }
            if(suf==0){
                suf=1;
            }
        }

        return ans;        
    }
};