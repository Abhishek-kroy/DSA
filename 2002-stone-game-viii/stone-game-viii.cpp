class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        for(int i=1;i<n;i++){
            stones[i]+=stones[i-1];
        }

        // so need a-b value to be optimal 
        // so both want to maximise the a and b as per them 
        // so ans tell from i to n-1 what is optimal value to take  
        // if a split i then b would optimally play so ans   

        int ans=stones[n-1];  

        for(int i=n-2;i>0;i--){
            // takes i+1 stones 
            int alice=stones[i]; 
            int b=ans;     

            ans=max(ans,alice-b);     
        }

        return ans; 
    }
};