class Solution {
public:
    bool isAnagram(string s, string t) {

        if((int)s.size()!=(int)t.size()){
            return false; 
        }

        vector<int> f1(26,0);
        // vector<int> f2(26,0);            

        for(auto c:s){
            f1[c-'a']++;
        }

        for(auto c:t){
            f1[c-'a']--; 
        }

        for(int i=0;i<26;i++){
            if(f1[i]){    
                return false;
            }
        }

        return true;        
    }
};