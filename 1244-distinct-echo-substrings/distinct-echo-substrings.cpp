class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();

        int b=31;

        int mod=(int)1e9+7;

        vector<vector<long long>> v(n,vector<long long> (n,-1));     

        unordered_set<string> s;    

        int ans=0; 

        for(int i=0;i<n;i++){
            long long f=0;
            string str="";
            for(int j=i;j<n;j++){
                f=((f*b+text[j]-'a'+1)%mod);

                str+=text[j]; 

                int len=j-i+1;

                int k=i-len;

                if(k>=0){
                    long long f2=v[k][i-1];

                    if(f==f2){        
                        s.insert(str);
                    } 
                }

                v[i][j]=f;        
            }
        }

        ans=s.size();

        return ans;        
    }
};