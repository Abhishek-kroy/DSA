class Solution {
public:
    int getSum(int a, int b) {
        int c=0;
        int bitcnt=32;
        int ans=0;
        int bitset=0;
        while(bitcnt){
            bitcnt--;

            int b1=a&1;
            int b2=b&1;
            a=a>>1;
            b=b>>1;

            int sum=b1+b2+c;

            if(sum==0){
                // no need to set
            }
            else if(sum==1){
                ans=ans|(1<<bitset);
                c=0;
            }
            else if(sum==2){
                c=1;
            }
            else {
                ans=ans|(1<<bitset);
                c=1;
            }

            bitset++;

        }

        return ans;
    }
};