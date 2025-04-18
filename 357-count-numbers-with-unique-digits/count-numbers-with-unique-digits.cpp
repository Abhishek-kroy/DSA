class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return 10;
        }
        int ans=81;
        for(int i=2;i<n;i++){
            ans=ans*(9-i+1);
        }

        return ans+countNumbersWithUniqueDigits(n-1);
    }
};