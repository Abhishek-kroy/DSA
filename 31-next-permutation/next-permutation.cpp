class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // stack<pair<int,int>> st;
        int n=nums.size();
        int st=n-1;
        // st.push({nums.back(),n-1});
        for(int i=n-2;i>=0;i--){
            // if(nums[i]>=st.top().first){
            //     st.push({nums[i],i});
            // }
            if(nums[i]>=nums[st]){
                // st.push({nums[i],i});
                st--;
            }
            // else{
            //     int index;
            //     while(!st.empty() && st.top().first>nums[i]){
            //         index=st.top().second;
            //         st.pop();
            //     }
            //     swap(nums[i],nums[index]);
            //     sort(nums.begin()+i+1,nums.end());
            //     return;
            // }
            else{
                int index;
                while(st<n && nums[st]>nums[i]){
                    index=st;
                    // st.pop();
                    st++;
                }
                swap(nums[i],nums[index]);
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());

        return ;        
    }
};
