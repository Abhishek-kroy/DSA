class Solution {
public:
    unordered_map<long long,long long> dp;

    long long getans(vector<int>& nums,long long i){        
        long long n=nums.size();                  

        if(i>=n){
            return 0;    
        }    

        if(dp.count(i)){
            return dp[i];
        }

        long long w1=nums[i]+(((nums[i]%3)==0) ? -getans(nums,i+1):+getans(nums,i+1));    

        long long w2= LLONG_MIN;

        if(i+1<n){
            w2=nums[i]+nums[i+1]+((((nums[i]+nums[i+1])%3)==0) ? -getans(nums,i+2): +getans(nums,i+2));
        }

        long long ans = max(w1,w2);

        return dp[i]=ans;    
    }

    long long maxDifference(vector<int>& nums) {
        dp.clear();
        return getans(nums,0);        
    }
};      