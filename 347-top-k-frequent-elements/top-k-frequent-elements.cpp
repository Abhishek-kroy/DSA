class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> freq;
        for(auto val:nums){
            freq[val]++;
        }

        vector<vector<int>> res(n+1);
        for(auto& p:freq){
            int num=p.first;
            int fre=p.second;
            res[fre].push_back(num);
        }        
        vector<int> ans;                
        for(int i=n;i>0 && k>0;i--){
            for(int j=0;j<(int)res[i].size() && k>0;j++){
                ans.push_back(res[i][j]);
                k--;      
            }
        }

        return ans;        
    }
};