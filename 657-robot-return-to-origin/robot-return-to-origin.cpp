class Solution {
public:
    bool judgeCircle(string moves) {
        int r=0;
        int u=0;

        for(auto c:moves){
            if(c=='U'){
                u++;
            }
            else if(c=='D'){
                u--;
            }
            else if(c=='L'){   
                r--;
            }
            else{
                r++; 
            }
        }

        cout<<u<<" "<<r<<endl;   

        return u==0 && r==0; 
    }
};