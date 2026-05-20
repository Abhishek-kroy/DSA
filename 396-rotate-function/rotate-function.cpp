class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int n=nums.size();

        long long total=0;

        for(int i=0;i<n;i++){
            total+=nums[i];
        }

        int ans=0;

        int score1=0;
        
        for(int i=0;i<n;i++){
            score1+=(i*nums[i]);
        }

        ans=score1;

        for(int i=1;i<n;i++){
            int nscore1=score1;
            nscore1-=(total-nums[i-1]);

            nscore1+=(n-1)*nums[i-1];

            ans=max(ans,nscore1);

            score1=nscore1;
        }

        return ans;   

    }
};