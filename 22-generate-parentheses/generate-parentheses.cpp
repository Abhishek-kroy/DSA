class Solution {
public:
    unordered_set<string> st;
    void getans(int n,string s,int o,int c){
        if(n==0){
            if(o==c){
                st.insert(s);
            }
            return ;
        }

        if(c>o) return ;

        getans(n-1,s+"(",o+1,c);
        getans(n-1,s+")",o,c+1);
    }
    vector<string> generateParenthesis(int n) {
        getans(2*n,"",0,0);
        
        return vector<string> (st.begin(),st.end());
    }
};