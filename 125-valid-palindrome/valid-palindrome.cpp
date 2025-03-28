class Solution {
public:
    bool isPalindrome(string s) {
        string s1="";
        for(auto c:s){
            if(c>='a' and c<='z'){
                s1+=c;
            }
            else if(c>='0' and c<='9'){
                s1+=c;
            }
            else if(c>='A' and c<='Z'){
                s1+=('a'+(c-'A'));
            }
        }

        for(int i=0;i<s1.size()/2;i++){
            if(s1[i]!=s1[s1.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};