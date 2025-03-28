class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s)   {
            if(c=='(' || c=='{' || c=='[')  st.push(c);
            else{
                if(st.empty())  return false;
                else if(c==')' and st.top()=='(')   st.pop();
                else if(c=='}' and st.top()=='{')   st.pop();
                else if(c==']' and st.top()=='[')   st.pop();
                else    return false;
            }
        }
        return st.empty();
    }
};