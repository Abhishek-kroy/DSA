class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> f;

        for(auto c:nums){
            f[c]++;  
        }

        int n=nums.size();

        vector<vector<int>> v((int)nums.size()+1);

        for(auto p:f){
            int val=p.first;
            int freq=p.second;

            v[freq].push_back(val);
        }

        vector<int> ans; 

        for(int i=n;i>=0 && k>0;i--){
            for(auto val:v[i]){
                ans.push_back(val);
            }      

            k-=v[i].size();                                                      
        }

        return ans;          
    }
};