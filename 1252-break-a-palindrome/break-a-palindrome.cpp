class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1)    return "";
        if(palindrome.size()%2==0){
            for(int i=0;i<palindrome.size()/2;i++){
                if(palindrome[i]!='a'){
                    palindrome[i]='a';
                    return palindrome;
                }
            }
            palindrome.back()='b';
            return palindrome;

        }
        for(int i=0;i<palindrome.size()/2;i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        if(palindrome[palindrome.size()/2]=='a')
            palindrome.back()='b';
        else{
            palindrome.back()='b';
        }
        return palindrome;
    }
};