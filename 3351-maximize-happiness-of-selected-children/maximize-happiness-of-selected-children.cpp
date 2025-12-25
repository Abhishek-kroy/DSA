class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.begin(),happiness.end());
        long long ans=0;

        for(int i=n-1;i>=0 && k>0;i--,k--){  
            ans+=max(0,(happiness[i]-((n-1)-(i))));         
        } 

        return ans; 

    }
};