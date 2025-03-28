class Solution {
public:
    string compress(string s){
        int i=0;
        string ans="";
        while(i<s.size()){
            int cnt=0;
            char c=s[i];
            int j=i;
            while(j<s.size() and c==s[j]){
                cnt++;
                j++;
            }
            i=j;

            ans=ans+to_string(cnt);
            ans+=c;
        }

        return ans;
    }
    string countAndSay(int n) {
        queue<string> q;      
        n--;
        q.push("1");

        while(n--){
            string s=q.front();
            q.pop();
            q.push(compress(s));
        }

        return q.front();

    }
};