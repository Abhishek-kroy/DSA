class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        int n=nums.size();

        vector<pair<int,int>> f(n+1,{-1,-1});   

        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            int val=nums[i];

            if(f[val].first==-1){
                f[val].first=i;
            }
            else if(f[val].second==-1){
                f[val].second=i;
            }
            else{
                int i1=f[val].first;
                int i2=f[val].second;
                int i3=i;   
                ans=min(ans,i2-i1+i3-i2+i3-i1);
                f[val].first=i2;
                f[val].second=i3;
            }
        }


        if(ans==INT_MAX)return -1;
        return ans;
    }
};