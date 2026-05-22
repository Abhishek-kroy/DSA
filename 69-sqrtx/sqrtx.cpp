class Solution {
public:
    int mySqrt(int x) {
        int l=1;
        int r=x;

        int ans; 

        while(l<=r){
            int mid=l+(r-l)/2;

            if((1LL*mid*mid)==x){    
                ans=mid;
                break;
            }
            else if(1LL*mid*mid>x){
                r=mid-1;
            }
            else{
                ans=mid;    
                l=mid+1;
            }
        }

        return ans;   
    }
};