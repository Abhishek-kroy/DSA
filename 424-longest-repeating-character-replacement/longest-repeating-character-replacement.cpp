class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int> fq;
        int f=0;
        while(j<n){
            fq[s[j]]++;
            f=max(f,fq[s[j]]); 
            while(((j-i+1)-f)>k){  
                fq[s[i]]--;  
                i++;
            }
            ans=max(ans,(j-i+1));
            j++;        
        }

        return ans; 
    }
};