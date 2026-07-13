class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<string> grid(m);

        for(int i=0;i<m;i++){
            string str="";
            for(int j=0;j<n;j++){
                str+='#';
            }

            grid[i]=str;          
        }

        for(int i=0;i<n;i++){
            grid[0][i]='.';
        }

        for(int j=0;j<m;j++){
            grid[j][n-1]='.';
        }

        if(k==1){
            return grid;
        }

        if(n>=2 && m>=2){
            grid[1][n-2]='.';
        }
        else{
            return {};
        }

        if(k==2){
            return grid; 
        }

        if(m>=3){
            grid[2][n-2]='.';                        
        }
        else if(n>=3){
            grid[1][n-3]='.';
        }
        else{
            return {};
        }

        if(k==3){
            return grid;
        }

        if(m>=4){
            grid[3][n-2]='.';
        }
        else if(n>=3 && m>=3 && grid[2][n-1]=='.'){
            grid[1][n-3]='.';
            grid[0][n-1]='#';
        }
        else if(n>=4){
            grid[1][n-4]='.';
        }
        else{
            return {};
        }

        return grid; 
    }
};