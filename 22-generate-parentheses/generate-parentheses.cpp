class Solution {
public:
    void getans(int len,int o,string s,vector<string>& ans){
        if(len==0){
            ans.push_back(s);
            return ;
        }

        // can we add (
        if((len-o)>0){
            getans(len-1,o+1,s+"(",ans);
        }
        if(o){
            getans(len-1,o-1,s+")",ans);
        }



    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        getans(2*n,0,"",ans);
        return ans;
    }
};