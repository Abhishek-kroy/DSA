class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(auto c:s){
            m[c]++;
        }
        unordered_map<char,int> m1;
        for(auto c:t){
            m1[c]++;
        }

        for(auto p:m){
            char c=p.first;
            if(m[c]!=m1[c]){
                return false;
            }
        }
        for(auto p:m1){
            char c=p.first;
            if(m[c]!=m1[c]){
                return false;
            }
        }

        return true;
    }
};