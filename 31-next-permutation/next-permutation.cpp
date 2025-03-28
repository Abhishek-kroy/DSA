class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        stack<pair<int,int>> st;
        int n=nums.size();
        st.push({nums.back(),n-1});
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=st.top().first){
                st.push({nums[i],i});
            }
            else{
                int index;
                while(!st.empty() && st.top().first>nums[i]){
                    index=st.top().second;
                    st.pop();
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
