class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // 0 2 
        // 3 5
        // 4 6

        int n=nums.size();

        sort(nums.begin(),nums.end());

        int low=nums[0];
        int high=nums.back();

        vector<int> lr(n),rr(n);
        unordered_map<int,int> f;

        for(int i=0;i<n;i++){
            int v=nums[i];
            f[v]++;
            lr[i]=v-k;
            rr[i]=v+k;
        }

        int ans=0;


        for(int i=low-k;i<high+k+1;i++){
            int ind=upper_bound(lr.begin(),lr.end(),i)-lr.begin();
            int ind2=lower_bound(rr.begin(),rr.end(),i)-rr.begin();

            // int cntL = upper_bound(lr.begin(), lr.end(), i) - lr.begin();
            // int cntR = lower_bound(rr.begin(), rr.end(), i) - rr.begin();

            int total=ind-ind2;
            int rem=total-f[i];
            ans=max(ans,min(rem,numOperations)+f[i]);
        }

        return ans;

    }
};