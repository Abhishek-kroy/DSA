class Solution {
public:
    string geten(string s){
        vector<int> f(26,0);
        for(auto v:s){
            f[v-'a']++;
        }
        string str="";
        for(auto v:f){
            str+=v;
        }
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(auto str:strs){
            string en=geten(str);
            m[en].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto p:m){
            ans.push_back(p.second);
        }

        return ans;
    }
};