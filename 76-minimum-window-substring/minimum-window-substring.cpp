class Solution {
public:
    bool issame(unordered_map<char,int>& f1,unordered_map<char,int>& f2){
        for(char c='a';c<='z';c++){
            if(f1[c]<f2[c]){
                return false; 
            }
        }
        for(char c='A';c<='Z';c++){
            if(f1[c]<f2[c]){    
                return false; 
            }
        } 

        return true;        
    }

    string minWindow(string s, string t) {
        unordered_map<char,int> f2;
        for(auto c:t){
            f2[c]++;                                    
        }

        int i=0;    

        int ans=INT_MAX;
        int st=(int)s.size();
        int end=0;
        string str=""; 

        unordered_map<char,int> f1;    

        for(int j=0;j<(int)s.size();j++){
            f1[s[j]]++;    

            while(issame(f1,f2)){
                if(ans>(j-i+1)){
                    ans=j-i+1;
                    st=i;
                    end=j; 
                }

                f1[s[i]]--;
                i++;
            }                    
        } 

        str=""; 
        for(int k=st;k<=end;k++){        
            str+=s[k]; 
        }

        return str;        
    }
};