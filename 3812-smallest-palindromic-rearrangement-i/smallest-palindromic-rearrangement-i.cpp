class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);

        for(auto c:s){
            freq[c-'a']++;
        }

        string ans1="";
        string ans2;

        for(int i=0;i<26;i++){
            while(freq[i]>=2){
                ans1+=('a'+i);
                freq[i]-=2;
            }
        }
        ans2=ans1;
        reverse(ans2.begin(),ans2.end());
        if(s.size()%2!=0){
            return ans1+s[s.size()/2]+ans2;
        }
        return ans1+ans2;
    }
};