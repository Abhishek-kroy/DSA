class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();

        if(n<2){
            return 0; 
        }

        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(auto val:nums){
            mini=min(mini,val);
            maxi=max(maxi,val);
        }

        int gap=((maxi-mini+n-1-1))/(n-1);

        vector<int> bmin(n-1,INT_MAX);
        vector<int> bmax(n-1,INT_MIN); 

        for(int i=0;i<n;i++){
            if(nums[i]==mini || nums[i]==maxi){
                continue;
            }

            int ind=(nums[i]-mini)/gap;           

            bmin[ind] = min(bmin[ind], nums[i]);
            bmax[ind] = max(bmax[ind], nums[i]);                        
        }

        int ans=0; 

        int prev=mini; 

        for(int i=0;i<n-1;i++){
            if(bmin[i]==INT_MAX){
                continue;                                
            }

            ans=max(ans,bmin[i]-prev);
            prev=bmax[i];                                    
        }

        ans=max(ans,maxi-prev);         

        return ans; 
    }
};