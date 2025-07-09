class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        if (n < 5) return 0;

        vector<vector<vector<int>>> pre(10,vector<vector<int>>(10,vector<int>(s.size())));
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                long long cnti=0;
                long long cntj=0;
                for(int k=0;k<s.size();k++){
                    if(s[k]-'0'==j){
                        cntj=(cntj+cnti)%((int)1e9+7);
                    }
                    if(s[k]-'0'==i){
                        cnti++;
                    }
                    pre[i][j][k]=cntj;
                }
            }
        }
        vector<vector<vector<int>>> suf(10,vector<vector<int>>(10,vector<int>(s.size())));
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                long long cnti=0;
                long long cntj=0;
                for(int k=s.size()-1;k>=0;k--){
                    if(s[k]-'0'==i){
                        cnti=(cnti+cntj)%((int)1e9+7);
                    }
                    if(s[k]-'0'==j){
                        cntj++;
                    }
                    suf[i][j][k]=cnti;
                }
            }
        }

        long long ans=0;

        for(int k=2;k<s.size()-2;k++){
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    long long cnt=1LL*pre[i][j][k-1]*suf[j][i][k+1];
                    ans=(ans+cnt)%((int)1e9+7);
                }
            }
        }

        return ans;
    }
};