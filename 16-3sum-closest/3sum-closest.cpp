class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end()); 

        int n=nums.size(); 

        int ans=INT_MAX; 

        int ele=-1; 

        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int d=abs(target-sum);

                if(d<ans){
                    ele=sum;
                    ans=d; 
                }

                if(sum>target){
                    k--;
                }
                else{
                    j++; 
                }
            }
        }

        return ele; 
    }
};