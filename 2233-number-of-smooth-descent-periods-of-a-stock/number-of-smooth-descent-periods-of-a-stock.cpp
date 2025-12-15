class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long cnt=0;
        int i=0;
        int n=prices.size();
        while(i<n){
            int j=i+1;
            while(j<n && prices[j]==prices[j-1]-1){
                j++;
            }
            long long size=j-i;     
            cnt+=(size*(size+1)/2); 
            cout<<size<<" "<<cnt<<endl;     
            i=j;                   
        }

        return cnt;
    }
};