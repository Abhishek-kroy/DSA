class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto s:queries){
            int i=0;
            for(auto c:s){
                if(i>=pattern.size() and c>='A' and c<='Z'){
                    i=0;
                    break;
                }
                if(c>='A' and c<='Z' and pattern[i]==c){
                    i++;
                }
                else if(c>='A' and c<='Z' and pattern[i]!=c){
                    i=0;
                    break ;
                }
                else if(pattern[i]==c){
                    i++;
                }
            }

            if(i>=(int)pattern.size())
                ans.push_back(true);
            else{
                ans.push_back(false);
            }
            for(auto i:ans){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        return ans;
    }
};