class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        map<pair<long long,int>,long long> ind;    
        long long ans=0;
        long long s=0;  

        int n=capacity.size();         
        for(int i=0;i<n;i++){
            s+=capacity[i];
            long long s1=s-2*capacity[i];           

            ans+=ind[{s1,capacity[i]}];  
            if(i>0 && capacity[i-1]==capacity[i] && capacity[i]==0){  
                ans--; 
            }

            ind[{s,capacity[i]}]++;   
        }

        return ans;
    }
};