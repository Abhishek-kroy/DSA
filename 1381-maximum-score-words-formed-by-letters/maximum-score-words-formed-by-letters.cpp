class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        int N=1<<n;

        vector<int> freq(26,0);
        for(auto c:letters){
            freq[c-'a']++;
        }

        int ans=0;

        for(int mask=1;mask<=N;mask++){
            vector<int> f(26,0);
            bool possible=true;
            for(int i=0;i<n && possible;i++){
                if(mask&(1<<i)){
                    for(auto w:words[i]){
                        f[w-'a']++;
                        if(f[w-'a']>freq[w-'a']){
                            possible=false;
                            break;
                        }
                    }
                }
            }
            int sco=0;
            if(possible){
                for(int i=0;i<26;i++){
                    sco+=(f[i]*score[i]);
                }
            }

            ans=max(ans,sco);        
        }

        return ans;            
    }
};