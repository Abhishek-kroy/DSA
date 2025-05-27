class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum1=n*(n+1)/2;
        if(n<m){
            return sum1;
        }
        int k=(n-m)/m+1;
        int sum2=k*m*(k+1)/2;
        return sum1-2*sum2;
    }
};