class Solution {
public:
    string shortestPalindrome(string s) {
        // aabba
        // abbaaabba
        // aabbaabbaa

        // aacecaaa
        // aaacecaaacecaaa

        int base=31;
        int mod=1e9+7;

        long long front=0;
        long long rev=0;
        int ind=-1;

        long long power=1;  

        int n=s.size();

        for(int i=0;i<n;i++){
            char c=s[i]-'a'+1;
            front=(front*base+(c))%mod;
            rev=(rev+(c*power))%mod;

            power=(power*base)%mod;

            if(front==rev){
                ind=i;
            }
        }

        ind++;
        string rem;
        rem.reserve(n-ind);
        while(ind<n){
            rem.push_back(s[ind]);
            ind++;   
        }

        reverse(rem.begin(),rem.end());  

        

        

        return rem+s;         

    }
};
// abbacdf
// fdcabbabbacdf