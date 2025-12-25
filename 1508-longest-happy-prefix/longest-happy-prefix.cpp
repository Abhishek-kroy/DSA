class Solution {
public:
    string longestPrefix(string s) {
        int ind=-1;

        int n=s.size(); 

        int l=0;
        int r=n-1;
        int base=31;
        long long power=1;
        int mod=1e9+7;

        long long pre=0;
        long long suf=0;
        while(l<n-1){

            char c=s[l]-'a'+1;
            pre=(pre*base+c)%mod;

            char c2=s[r]-'a'+1;
            suf=(suf+c2*power)%mod;

            power=(power*base)%mod;  

            if(pre==suf){
                ind=l;
            }

            l++;
            r--;
        }

        string ans;
        ans.reserve(ind+1);

        for(int i=0;i<=ind;i++){
            ans.push_back(s[i]);
        }

        return ans;    
    }
};