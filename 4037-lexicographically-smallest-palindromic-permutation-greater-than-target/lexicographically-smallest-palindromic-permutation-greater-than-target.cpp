class Solution {
public:
    unordered_map<char,int> f;
    char odd=' ';
    string ans="";
    
    void getans(string& s,string& target,int n,int i,bool tight,string res){
        if(i==n/2){
            string temp=res;
            reverse(temp.begin(),temp.end());        

            string t=res;
            if(odd!=' '){
                t+=odd;
            }
            t+=temp;        

            if(t>target){
                if(ans==""){
                    ans=t;
                }
                ans=min(ans,t);
            }

            return ;        
        }

        if(tight){
            int cnt=0;
            for(auto c=target[i];c<='z';c++){
                if(f[c]>=2){
                    f[c]-=2;
                    getans(s,target,n,i+1,tight&&(c==target[i]),res+c);
                    f[c]+=2;
                    cnt++;
                    if(cnt>=2){
                        break;
                    }
                }
            }
        }
        else{
            for(auto c='a';c<='z';c++){
                if(f[c]>=2){
                    f[c]-=2;
                    getans(s,target,n,i+1,false,res+c);
                    f[c]+=2;
                    break;
                }
            }
        }


    }
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        for(auto c:s){
            f[c]++;
        }
        int cnt=0;

        for(auto p:f){
            if(p.second%2){
                odd=p.first;
                cnt++;
            }
        }        

        if(cnt>=2){
            return "";
        }

        getans(s,target,n,0,true,"");

        return ans;
    }
};