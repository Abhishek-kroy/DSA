class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n=s.size();
        vector<int> p(n,-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(!st.empty()){
                p[i]=st.top();
                st.pop();
            }
        }




        int ans=0;

        int i=n-1;
        while(i>=0){
            int t=0;
            while(i>=0 and p[i]!=-1){
                t+=i-p[i]+1;
                cout<<t<<endl;
                i=p[i]-1;
            }

            ans=max(ans,t);

            i--;
        }

        return ans;
    }
};