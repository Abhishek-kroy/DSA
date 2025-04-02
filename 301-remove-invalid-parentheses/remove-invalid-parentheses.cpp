class Solution {
    void getans(string &s, int i, int close, int open, string &par, int &max_len, unordered_set<string> &unique_res) {
        if (close > open) return;

        if (i >= s.size()) {
            if (open == close) {
                if (par.size() > max_len) {
                    max_len = par.size();
                    unique_res.clear();
                }
                if (par.size() == max_len) {
                    unique_res.insert(par);
                }
            }
            return;
        }

        char c = s[i];
        
        int len = par.size();

        if (c != ')') {
            if (c == '(') {
                par.push_back('(');
                getans(s, i + 1, close, open + 1, par, max_len, unique_res);
                par.pop_back();
                
                getans(s, i + 1, close, open, par, max_len, unique_res);
            } 
            else {
                par.push_back(c);
                getans(s, i + 1, close, open, par, max_len, unique_res);
                par.pop_back();
            }
        } 
        else {
            par.push_back(')');
            getans(s, i + 1, close + 1, open, par, max_len, unique_res);
            par.pop_back();
            
            getans(s, i + 1, close, open, par, max_len, unique_res);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> unique_res;
        int max_len = 0;
        string par = "";
        getans(s, 0, 0, 0, par, max_len, unique_res);

        return vector<string>(unique_res.begin(), unique_res.end());
    }
};