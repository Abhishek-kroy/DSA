class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],nums[i]);
        }

        vector<int> suf(n);
        suf[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            suf[i]=min(suf[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            int s=pre[i]-suf[i];
            if(s<=k){
                return i;        
            }
        }

        return -1;   
    }
};