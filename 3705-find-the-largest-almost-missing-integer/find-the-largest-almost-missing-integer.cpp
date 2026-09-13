class Solution { 
public: 
    int largestInteger(vector<int>& nums, int k) { 
        unordered_map<int,int> f;           
 
        if(k==1){ 
            for(auto v:nums){            
                f[v]++; 
            } 
 
            int ans=-1;                   
 
            for(auto v:nums){ 
                if(f[v]==1){ 
                    ans=max(ans,v); 
                } 
            } 
 
            return ans; 
        }            
 
        if(k==nums.size()){ 
            int ans=0; 
            for(auto v:nums){ 
                ans=max(ans,v); 
            } 
 
            return ans; 
        } 
 
        int ans=-1; 
 
        for(auto v:nums){ 
            f[v]++;  
        } 
 
        if(f[nums[0]]==1){ 
            ans=max(ans,nums[0]); 
        } 
 
        if(f[nums[nums.size()-1]]==1){ 
            ans=max(ans,nums[nums.size()-1]); 
        } 
 
        return ans;         
    } 
};