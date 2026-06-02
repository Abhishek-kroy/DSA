class Solution {
public:
    int atmost(vector<int>& nums,int k){
        if(k<0){
            return 0;
        }

        int n=nums.size();

        int cnt=0;

        int ans=0; 

        int i=0;

        int j=0; 

        while(j<n){
            if(nums[j]%2){
                cnt++;
            }

            while(cnt>k){
                if(nums[i]%2){           
                    cnt--;
                }

                i++; 
            }

            ans+=(j-i+1);

            j++;      

        }

        return ans; 
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};