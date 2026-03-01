class Solution {
public:
    bool getans(vector<vector<char>>& board, string& word,int ind,int i,int j,vector<bool>& f){     
        int n=board.size();
        int m=board[0].size();   
        if(ind>=word.size()){
            return true;  
        }
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }    


        if(board[i][j]!=word[ind]){
            return false; 
        }

        if(f[i*m+j]){            
            return false;   
        }

        f[i*m+j]=true;    

        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1}; 

        for(int k=0;k<4;k++){    
            int ni=i+dx[k];
            int nj=j+dy[k];

            if(getans(board,word,ind+1,ni,nj,f)){          
                f[i*m+j]=false;           
                return true;
            }
            // else{
            //     f[i*m+n][ind]=false;
            // }
        }

        f[i*m+j]=false;            

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();   

        vector<int> cnt(128,0);
        for(auto r:board) for(char c:r) cnt[c]++;
        for(char c:word) if(--cnt[c]<0) return false;

        vector<bool> f(n*m,false);    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(getans(board,word,0,i,j,f)){        
                        return true;
                    }
                }
            }
        }   

        return false;  
    }
};