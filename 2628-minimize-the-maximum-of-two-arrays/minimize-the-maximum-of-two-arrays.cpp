class Solution {
public:
    bool check(long long d1,long long d2,long long u1,long long u2,long long mid){
        if(mid<u1+u2)   return false;
        long long r1=mid-(mid/d1);
        long long r2=mid-(mid/d2);
        long long com=(d1/__gcd(d1,d2)*d2);
        long long rem=mid-(mid/com);

        return (r1>=u1 && r2>=u2 && rem>=u1+u2);
    }

    int minimizeSet(long long divisor1, long long divisor2, long long uniqueCnt1, long long uniqueCnt2) {
        long long l=1;
        long long r=1e18;  
        long long ans;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(divisor1,divisor2,uniqueCnt1,uniqueCnt2,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};