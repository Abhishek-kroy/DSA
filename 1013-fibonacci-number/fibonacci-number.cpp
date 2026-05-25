class Solution {
public:
    int fib(int n) {
        if(n<=1){
            return n;
        }

        int ptr1=0;

        int ptr2=1;

        n-=1;    

        while(n-- > 0){
            int nptr=ptr1+ptr2;
            ptr1=ptr2;
            ptr2=nptr;                        
        }

        return ptr2; 
    }
};