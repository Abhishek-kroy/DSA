class Solution {
public:
    long long flowerGame(int n, int m) {
        int odd=m/2 + (m%2!=0 ? 1:0);
        int even=m/2;

        long long ans=0;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                ans+=odd;
            }
            else{
                ans+=even;
            }
        }

        return ans;
    }
};