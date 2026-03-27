class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {

        // abacaba
        // aba caba

        int n=word.size();

        int ans=(n+k-1)/k;    

        long long base=31;
        long long power=1;
        int mod=1e9+7 ; 

        long long f1=0;
        long long f2=0;

        int i=0;
        int j=n-1;

        while(i<n-1){
            f1=(f1*base+(word[i]-'a'+1))%mod;
            f2=((word[j]-'a'+1)*power+f2)%mod;      

            if(j%k==0 && f1==f2){    
                ans=min(ans,j/k);                                
            }    

            power=(power*base)%mod;

            j--;

            i++;  
        }

        return ans;    
    }
};