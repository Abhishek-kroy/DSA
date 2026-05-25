class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();

        int ans=INT_MAX; 

        long long sum=0;

        deque<pair<long long,int>> q;
        q.push_back({0,-1});    

        for(int i=0;i<n;i++){
            sum+=nums[i];

            // prefix[i]-prefix[j]>=k
            // prefix[j]<=prefix[i]-k    

            while(!q.empty() && q.front().first<=(sum-k)){    
                auto [val,ind]=q.front();
                q.pop_front();

                ans=min(ans,i-ind);    
            }

            while(!q.empty() &&  q.back().first>=sum){
                q.pop_back();
            }

            q.push_back({sum,i});
        }

        return ans==INT_MAX ? -1 :ans ;    
    }
};