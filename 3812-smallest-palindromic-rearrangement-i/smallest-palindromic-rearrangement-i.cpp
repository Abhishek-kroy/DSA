class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char,int> f;

        for(auto c:s){
            f[c]++;
        }

        string str="";

        char mid='-';

        for(int i=0;i<26;i++){        
            int cnt=f[('a'+i)];

            for(int j=0;j<cnt/2;j++){
                str+=('a'+i);
            }



            if(cnt%2){
                mid=('a'+i);
            }
        }
        string ans=str;

        reverse(str.begin(),str.end());

        if(mid=='-'){
            return ans+str;
        }
        ans+=mid;

        return ans+str;      
    }
};