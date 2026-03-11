class Solution {
public:
    int bitwiseComplement(int n) {
        int t=n;    
        if(t==0){
            return 1; 
        }
        for(int i=0;i<31 && t;i++){    
            int b=(n&(1<<i))?1:0;
            if(b){
                n=n&(~(1<<i));    
            }
            else{
                n=n|(1<<i);
            }
            t=t>>1;    
        }

        return n;    
    }
};