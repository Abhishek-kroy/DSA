class Solution {
public:
    void getlps(vector<int>& lps,string& needle,int m){
        lps[0]=0;

        int len=0;

        int i=1; 

        while(i<m){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{

                if(len>0){
                    len=lps[len-1];
                }                     
                else{
                    lps[i]=0;
                    len=0;
                    i++; 
                }                           
            }
        }
    }

    int strStr(string haystack, string needle) {
        int n=haystack.size();

        int m=needle.size();

        vector<int> lps(m);

        getlps(lps,needle,m);

        int i=0;

        int j=0;

        // vector<int> l(n,0); 

        int ans=-1; 

        while(i<n){
            if(haystack[i]==needle[j]){
                i++; 
                j++;          

                if(j==m && ans==-1){
                    ans=i-m;
                } 
            }
            else{
                // l[i]=j+1; 


                if(j>0){
                    j=lps[j-1];
                }
                else{
                    i++; 
                }
            }
        }

        return ans; 
    }
};