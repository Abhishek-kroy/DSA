// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int r=INT_MAX;

        while(l<=r){
            long long mid=1LL*l+(1LL*(r-l)/2);

            if(isBadVersion(mid)){
                r=mid-1;
            }
            else{
                l=mid+1;    
            }
        }

        return l; 
    }
};