class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.size();

        int z=0;

        int cone=0;

        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                z++;
                cone=max(0,cone-1);          
            }
            if(s[i]=='1'){
                ans=max(ans,z ? z+cone:0);
                if(z)
                    cone++;
            }
        }

        // 100011

        return ans;
    }
};