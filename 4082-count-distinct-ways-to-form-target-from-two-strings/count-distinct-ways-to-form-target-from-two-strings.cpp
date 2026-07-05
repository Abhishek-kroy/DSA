class Solution {
public:
    const int mod = 1e9+7;                     

    vector<vector<vector<int>>> dp; 
    int getans(string& word1,string& word2,string& target,int i,int j,int k){
        int n=word1.size();        
        int m=word2.size();        
        int l=target.size();        


        if(k==l){
            if(i==0 || j==0){
                return 0; 
            }

            return 1;
        }

        if(i>=n && j>=m){      
            return 0; 
        }

         if(dp[i][j][k]!=-1)
        return dp[i][j][k]; 

        long long w1=0;

        for(int v=i;v<n;v++){
            if(word1[v]==target[k]){
                w1=(w1+getans(word1,word2,target,v+1,j,k+1))%mod;
            }
        }

        long long w2=0;

        for(int v=j;v<m;v++){
            if(word2[v]==target[k]){
                w2=(w2+getans(word1,word2,target,i,v+1,k+1))%mod;          
            }
        }

        return dp[i][j][k]=(w1+w2)%mod;   
    }

    int interleaveCharacters(string word1, string word2, string target) {
         int n=word1.size();           
    int m=word2.size();
    int l=target.size();

    dp.assign(n+1, vector<vector<int>>(m+1, vector<int>(l+1, -1)));                         

        return getans(word1,word2,target,0,0,0);
    }
};