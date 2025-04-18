class Solution {
    map<int,string> m;
public:
    Solution(){
    m[1]="1";
    }
    string countAndSay(int n) {
       if(m.find(n) != m.end()){
        return m[n];
       }
       string res=countAndSay(n-1);
       string ans="";
       for(int i=0;i<res.size();i++){
            int cnt = 1; // Initialize count to 1 for the current digit
            while (i + 1 < res.size() && res[i] == res[i + 1]) {
                cnt++;
                i++;
            }
            ans += to_string(cnt) + res[i];
       }
       m[n]=ans;
       return ans;
    }
};