class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        string ans="";

        int sz=0;

        int st;
        int end; 

        for(int i=0;i<n;i++){

            // odd length 
            int l=i;
            int r=i;

            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>sz){
                    st=l;
                    end=r; 

                    sz=r-l+1; 
                }

                l--;
                r++;
            }

            // even length 

            l=i;
            r=i+1; 

            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>sz){
                    st=l;
                    end=r;

                    sz=r-l+1; 
                }

                l--;
                r++;
            }
        }

        for(int i=st;i<=end;i++){
            ans+=s[i];
        }

        return ans;       
    }
};