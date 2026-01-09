class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        st.push(nums[n-1]);

        vector<int> ans(n,-1);

        for(int i=2*n-1;i>=0;i--){    
            int e=nums[i%n];

            while(!st.empty() && st.top()<=e){    
                st.pop();
            }

            if(!st.empty()){
                ans[i%n]=st.top();
            }
            st.push(e);
        }

        // while(!st.empty() && st.top()<=nums[n-1]){
        //     st.pop();
        // }

        // if(!st.empty()){
        //     ans[n-1]=st.top();
        // }

        return ans; 
    }
};