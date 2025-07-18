class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long ans=LLONG_MAX;

        // priority_queue<int,vector<int>,greater<int>> min_h;
        priority_queue<long long> max_h;
        int n=nums.size()/3;
        vector<long long> pref;
        long long sum=0;

        for(int i=0;i<3*n;i++){
            if(max_h.size()>=n){
                if(nums[i]<max_h.top()){
                    sum-=max_h.top();
                    max_h.pop();

                    sum+=nums[i];
                    max_h.push(nums[i]);
                }
            }
            else{
                max_h.push(nums[i]);
                sum+=nums[i];
            }
            pref.push_back(sum);
        }

        sum=0;
        priority_queue<long long,vector<long long>,greater<long long>> min_h;
        vector<long long> suf;

        for(int i=3*n-1;i>=0;i--){
            if(min_h.size()>=n){
                if(nums[i]>min_h.top()){
                    sum-=min_h.top();
                    min_h.pop();

                    sum+=nums[i];
                    min_h.push(nums[i]);
                }

            }
            else{
                    min_h.push(nums[i]);
                    sum+=nums[i];

            }
            suf.push_back(sum);
        }

        sum=0;

        reverse(suf.begin(),suf.end());

        for(int i=n-1;i<2*n;i++){
            ans=min(ans,1LL*pref[i]-suf[i+1]);
        }

        return ans;

    }
};