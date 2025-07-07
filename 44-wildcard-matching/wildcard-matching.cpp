class Solution {
public:
    map<pair<int, int>, bool> memo;

 bool match(const string& s, const string& p, int i, int j) {
        if (j == p.size()) return i == s.size(); 
        if (i == s.size()) {
            while (j < p.size() && p[j] == '*') j++;
            return j == p.size();
        }
        if (memo.find({i, j}) != memo.end()) return memo[{i, j}];

        if (p[j] == '*') {
            return memo[{i, j}] = match(s,p,i,j+1) || match(s,p,i+1,j);
        } else {
            if ((s[i] == p[j] || p[j] == '?')) {
                return memo[{i, j}] = match(s, p, i + 1, j + 1);
            }
        }
        
        return memo[{i, j}] = false;
    }

    bool isMatch(const string& s, const string& p) {
        memo.clear();
        return match(s, p, 0, 0);
    }
};