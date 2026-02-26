class Solution {
public:
    bool can(vector<int>& nums, int mid, int k){
        int i=0;
        int j=0;

        int n=nums.size();

        while(j<n){
            if((j-i+1)==mid){  
                if(1LL*nums[i]*k>=1LL*nums[j]){  
                    return true;
                }
                else{
                    i++;
                }

            }
            j++;

        }
        // if((j-i+1)==mid){  
        //     if(nums[i]*k>=nums[j]){
        //         return true;
        //     }
        //     else{
        //         i++;
        //     }

        // }  

        return false; 
    }

    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=1;
        int r=nums.size();
        int ans=1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(can(nums,mid,k)){
                ans=mid;   
                l=mid+1;    
            }
            else{
                r=mid-1;
            }
        }

        return nums.size()-ans;  
    }
};