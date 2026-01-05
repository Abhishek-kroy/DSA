class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt=0;
        int mini=INT_MAX;
        long long sum=0;      
        // long long neg_sum=0;   
        for(auto val:matrix){
            for(auto v:val){
                sum+=abs(v);
                mini=min(mini,abs(v)) ;
                if(v<0) cnt++;                               
            }
        }

        if(cnt%2==0){
            // cout<<sum<<" "<<abs(neg_sum)<<" "<<max_neg<<endl;  
            return sum;
        }

        // cout<<sum<<" "<<abs(neg_sum)<<" "<<max_neg<<endl;

        return sum-2*mini;             


    }
};