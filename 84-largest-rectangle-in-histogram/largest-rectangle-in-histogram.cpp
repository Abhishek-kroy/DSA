class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n=heights.size();
        vector<int> prev(n,-1);

        stack<int> st;
        st.push(0);

        int ans=0;
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int ind=st.top();
                int leftsize=ind-prev[ind];
                int rightsize=i-ind;
                int total=leftsize+rightsize-1;
                ans=max(ans,total*heights[st.top()]);
                st.pop();
            }

            prev[i]=!st.empty()?st.top():-1;
            st.push(i);
        }

        

        return ans;
    }
};