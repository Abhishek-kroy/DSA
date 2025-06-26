class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        s.push(0);
        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[s.top()]>=nums[i]){
                s.push(i);
            }
        }

        int ans=0;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i]){
                ans=max(ans,i-s.top());
                s.pop();
            }
        }

        return ans;
    }
};