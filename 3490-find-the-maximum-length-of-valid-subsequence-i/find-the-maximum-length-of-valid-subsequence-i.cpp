class Solution {
public:
    map<pair<pair<int,int>,int>,int> dp;
    int getans(vector<int>& nums,int i,bool iseven,int prev){
        if(i>=nums.size())  return 0;



        if(prev==-1){
            // take
            int w1=1+getans(nums,i+1,iseven,nums[i]);
            // not take
            int w2=getans(nums,i+1,iseven,prev);

            return max(w1,w2);
        }

        if(dp.find({{i,prev},iseven})!=dp.end())   return dp[{{i,prev},iseven}];

        if(iseven){
            int w1=0;
            if((prev+nums[i])%2==0){
                w1=1+getans(nums,i+1,iseven,nums[i]);
            }
            int w2=getans(nums,i+1,iseven,prev);

            return dp[{{i,prev},iseven}]=max(w1,w2);
        }
        int w1=0;
        if((prev+nums[i])%2!=0){
            w1=1+getans(nums,i+1,iseven,nums[i]);
        }
        int w2=getans(nums,i+1,iseven,prev);

        return dp[{{i,prev},iseven}]=max(w1,w2);
    }
    int maximumLength(vector<int>& nums) {
        // int w1=getans(nums,0,true,-1);
        // int w2=getans(nums,0,false,-1);        
        // return max(w1,w2);

        // odd odd
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0)    cnt++;
        }
        // even even
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)    cnt2++;
        }
        // even odd
        int cnt3=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                cnt3++;
                while(i<n && nums[i]%2==0){
                    i++;
                }
                if(i<n)
                cnt3++;
            }
        }
        // even odd
        int cnt4=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                cnt4++;
                while(i<n && nums[i]%2!=0){
                    i++;
                }
                if(i<n)
                cnt4++;
            }
        }

        return max({cnt,cnt2,cnt3,cnt4});
    }
};