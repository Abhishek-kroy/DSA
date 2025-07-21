class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        int f=0;
        int ans=0;
        vector<int> freq(26,0);
        for(int j=0;j<n;j++){
            freq[s[j]-'A']++;
            f=max(f,freq[s[j]-'A']);
            int ch=(j-i+1)-f;
            while((j-i+1)-f>k){
                freq[s[i]-'A']--;
                i++;
            }

            ans=max(ans,j-i+1);
        }

        return ans; 
    }
};