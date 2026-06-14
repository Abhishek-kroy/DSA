class Solution {
public:
    int check(vector<vector<int>>& board,int i,int j){
        int n=board.size();
        int m=board[0].size();

        int cnt=0;

        vector<int> dx={-1,-1,0,1,1,1,0,-1};
        vector<int> dy={0,1,1,1,0,-1,-1,-1};

        for(int k=0;k<8;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];           

                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    if(board[ni][nj]==2          || board[ni][nj]==1){
                        cnt++;
                    }
                }
        }

        return cnt;            
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();

        // live but dead => 2 

        // dead but live => 4 

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int nei=check(board,i,j);
                if(board[i][j]==0){
                    if(nei==3){
                        board[i][j]=4; 
                    }                                        
                }
                else{
                    if(nei<2 || nei>3){
                        board[i][j]=2;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2){
                    board[i][j]=0;
                }
                if(board[i][j]==4){
                    board[i][j]=1;
                }
            }
        }


    }
};