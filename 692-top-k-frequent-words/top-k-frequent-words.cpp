class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> f;

        for(auto word:words){
            f[word]++;        
        }

        unordered_map<int,vector<string>> t;
        for(auto p:f){
            t[p.second].push_back(p.first);
        }

        // for(auto p:t){
        //     cout<<"freq "<<p.first<<" ";
        //     for(auto str:p.second){
        //         cout<<str<<" ";        
        //     }
        //     cout<<endl;        
        // }

        vector<string> ans;

        for(int i=words.size();i>0 && k>0;i--){
            sort(t[i].begin(),t[i].end());        
            for(int j=0;j<t[i].size() && k>0;j++){        
                ans.push_back(t[i][j]);        
                k--;
            }
        }

        return ans;        
    }
};