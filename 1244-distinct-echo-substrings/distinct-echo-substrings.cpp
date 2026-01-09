class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<int> ans;
        int n=text.size();
        int base=31;
        int MOD=1e9+7;  

        for(int i=0;i<n-1;i++){
            int j=i;
            int st=i+1;
            int end=i+1;
            long long f=text[i]-'a'+1;
            long long s=text[i+1]-'a'+1;
            if(f==s){
                ans.insert(f); 
            }

            long long power=1;         

            while(end+2<n){  
                j++;
                f=(f*base+(text[j]-'a'+1))%MOD ; 

                s = ((s - ((text[st] - 'a' + 1) * power)%MOD)+MOD)%MOD;  
                power=(power*base)%MOD;

                st++;
                s=s*base;
                s=s*base;
                s=(s+((text[end+1]-'a'+1)*base)+(text[end+2]-'a'+1))%MOD;   
                end+=2; 

                
                if(f==s){
                    ans.insert(f); 
                }
            }


        }

        return ans.size()  ; 
    }
};