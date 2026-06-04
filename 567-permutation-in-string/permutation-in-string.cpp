class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26,0);

        for(auto c:s1){
            f1[c-'a']++;
        }

        int n=s2.size();

        int i=0;
        int j=0;

        vector<int> f2(26,0); 

        while(j<n){
            f2[s2[j]-'a']++;

            if((j-i+1)==(int)s1.size()){
                bool s=true;

                for(int k=0;k<26;k++){
                    if(f1[k]!=f2[k]){
                        s=false;
                        break;        
                    }
                }

                if(s)   return true;      

                f2[s2[i]-'a']--;

                i++; 
            }

            j++;
        }

        return false; 
    }
};