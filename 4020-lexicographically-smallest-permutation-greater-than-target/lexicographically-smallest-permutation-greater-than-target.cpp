class Solution {
public:
    string ans="";
    unordered_map<char,int> f;
    void getans(string& s,string& target,int i,bool tight,string& pal){
        int n=s.size();

        if(i>=n){
            if(ans==""){
                if(pal!=target){
                    ans=pal;
                }
            }
            else{
                ans=min(ans,pal);
            }

            return ;
        }

        if(tight){
            int cnt=0;
            for(auto c=target[i];c<='z';c++){
                if(f[c]>0){
                    f[c]--;
                    pal.push_back(c);
                    getans(s,target,i+1,tight && c==target[i],pal);
                    pal.pop_back();        
                    f[c]++;

                    cnt++;

                    if(cnt>=2){
                        break;
                    }
                }
            }
        }
        else{
            int cnt=0;
             for(auto c='a';c<='z';c++){
                if(f[c]>0){
                    f[c]--;
                    pal.push_back(c);
                    getans(s,target,i+1,tight,pal);
                    pal.pop_back();    
                    f[c]++;

                    cnt++;

                    if(cnt>=1){
                        break;
                    }
                }
            }
        }
    }
    string lexGreaterPermutation(string s, string target) {
        string pal="";

        for(auto c:s){
            f[c]++;
        }        

        getans(s,target,0,true,pal);

        if(ans==target){
            return "";
        }

        return ans;
    }
};