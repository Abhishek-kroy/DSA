class Solution {
public:
    int getans(vector<int> &nums,int v){
        int cnt=1;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=v){
                sum+=nums[i];
            }
            else{
                cnt+=1;
                sum=nums[i];
            }
        }

        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right=0;
        for(auto v:nums){
            right+=v;
        }


        int ans;
        while(left<=right){
            int mid=left+(right-left)/2;
            int cnt=getans(nums,mid);
            if(cnt<=k){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }

        return ans;
    }
};