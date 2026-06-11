class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();

        vector<int> z(n);
        z[0]=0;

        int l=0;
        int r=0;

        for(int i=1;i<n;i++){
            if(i<r){
                z[i]=min(r-i,z[i-l]);

            }
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }

            if(i+z[i]>r){
                l=i;
                r=i+z[i];
            }
        }

        for(int i=1;i<n;i++){
            if(i+z[i]==n){
                return s.substr(i,z[i]);
            }
        }

        return ""; 
    }
};