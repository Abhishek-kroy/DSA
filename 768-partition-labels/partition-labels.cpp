class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]=i;
        }

        vector<int> ans;
        for(int i=0;i<s.size();i++){
            int end=m[s[i]];
            int j=0;
            while(j<end){
                end=max(end,m[s[j]]);
                j++;
            }
            ans.push_back(end+1-i);
            i=j;
        }

        return ans;
    }
};