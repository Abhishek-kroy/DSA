class Solution {
public:
    int getans(int n,int i,int mask){
        if(i==n){
            return mask!=0;    
        }

        int w1=mask==0 ? getans(n,i+1,mask):0;      

        for(int j=0;j<=9;j++){   
            if(!mask && j==0){
                continue;
            }       
            if(!(mask&(1<<j))){
                int nmask=mask|(1<<j);
                w1+=getans(n,i+1,nmask);
            }
        }

        return w1;
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }

        return getans(n,0,0)+1;          
    }
};