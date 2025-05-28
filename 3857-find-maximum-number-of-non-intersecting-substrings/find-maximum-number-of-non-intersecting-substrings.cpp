class Solution {
public:
    int maxSubstrings(string word) {
        unordered_map<char,int> m;
        int ans=0;
        for(int i=0;i<word.size();i++){
            if(m.find(word[i])==m.end()){
                m[word[i]]=i;
            }
            else{
                int j=m[word[i]];
                if(i-j>=3){
                    ans++;
                    m.clear();
                }
            }
        }
        return ans;
    }
};