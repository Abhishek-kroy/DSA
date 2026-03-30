class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        string str1="";
        string str2="";

        for(int i=0;i<n1;i+=2){
            str1+=s1[i];
        }
        for(int i=0;i<n2;i+=2){
            str2+=s2[i];
        }

        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());

        if(str1!=str2){
            return false;
        }

        str1="";
        str2="";
        for(int i=1;i<n1;i+=2){
            str1+=s1[i];
        }
        for(int i=1;i<n2;i+=2){
            str2+=s2[i];
        }
        
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());   

        return str1==str2;   
    }
};