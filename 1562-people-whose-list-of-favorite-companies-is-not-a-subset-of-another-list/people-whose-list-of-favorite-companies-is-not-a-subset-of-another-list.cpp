class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<int,unordered_set<string>> fv;
        int n=favoriteCompanies.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<favoriteCompanies[i].size();j++){
                fv[i].insert(favoriteCompanies[i][j]);
            }
        }

        vector<int> ans;

        for(int i=0;i<n;i++){
            bool subs=false;
            for(int j=0;j<n;j++){
                if(i==j || favoriteCompanies[i].size()>favoriteCompanies[j].size()){
                    continue;
                }

                bool tsubs=true;
                for(int k=0;k<favoriteCompanies[i].size();k++){
                    if(fv[j].find(favoriteCompanies[i][k])==fv[j].end()){
                        tsubs=false;
                        break;                                                
                    }                                        
                }

                if(tsubs){
                    subs=true;
                    break;
                }
            }

            if(!subs){
                ans.push_back(i);    
            }
        }

        return ans;        
    }
};