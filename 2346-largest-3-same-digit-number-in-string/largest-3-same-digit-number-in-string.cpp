class Solution {
public:
    string largestGoodInteger(string num) {
        string s="";
        int n=num.size();
        for(int i=1;i<n-1;i++){
            if(num[i]==num[i-1] && num[i]==num[i+1]){
                if(s=="" || (num[i]-'0')>(s[0]-'0')){
                    s="";
                    s+=num[i];
                    s+=num[i];
                    s+=num[i];
                }
            }
        }

        return s;
    }
};