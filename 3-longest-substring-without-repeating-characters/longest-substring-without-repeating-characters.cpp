class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        unordered_set<int> s1;
        int ans=0;
        while(j<s.size()){
            if(s1.find(s[j])==s1.end()){
                s1.insert(s[j]);
                j++;
                ans=max(ans,j-i);
            }
            else{
                while(s[i]!=s[j]){
                    s1.erase(s[i]);
                    i++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};