class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int,int> freq;

        int maxi=0;

        for(auto val:nums){
            freq[val]++;
            maxi=max(maxi,freq[val]);
        }

        unordered_map<int,vector<int>> f;        

        for(auto p:freq){
            for(int i=1;i<=p.second;i++){
                f[i].push_back(p.first);
            }
        }

        vector<int> ans;

        for(int t=1;t<=maxi;t++){        
            sort(f[t].begin(),f[t].end());

            for(auto v:f[t]){
                ans.push_back(v);    
            }
        }

        return ans;        
    }
};