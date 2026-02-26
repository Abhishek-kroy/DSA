class Solution {
public:
    int minimumDeletions(string s) {
        int ta=0;
        int tb=0;
        for(auto c:s){
            if(c=='a'){
                ta++;
            }
            else{
                tb++;
            }
        }

        int a=0;
        int b=0;
        int ans=min(ta,tb);
        int n=s.size();
        for(int i=0;i<n;i++){
            ans=min(ans,ta-a+b);
            if(s[i]=='a'){
                a++;
            }       
            else{
                b++;
            }       
            ans=min(ans,ta-a+b);          
        }

        return ans; 
    }
};