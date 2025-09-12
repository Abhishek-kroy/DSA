class Solution {
public:
    bool doesAliceWin(string s) {
        int vowel=0;
        for(auto c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')  return true;
        }

        return false ;  
        
    }
};