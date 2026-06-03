class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();

        int i=0;
        int j=n-1;

        while(i<j){
            while(i<j && !((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))){
                i++;
            }

            while(i<j && !((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9'))){        
                j--;
            }

            if(tolower(s[i])==tolower(s[j])){  
                i++;
                j--; 
            }
            else{
                cout<<i<<" "<<j<<endl; 
                return false; 
            }

        }

        return true;    
    }
};