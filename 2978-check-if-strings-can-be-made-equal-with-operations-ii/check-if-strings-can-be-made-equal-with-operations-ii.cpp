class Solution {
public:
    bool checkStrings(string s1, string s2) {

        int n1=s1.size();
        int n2=s2.size();

        vector<int> c1(26,0);
        vector<int> c2(26,0);

        for(int i=0;i<n1;i++){
            if(i%2==0){
                c1[s1[i]-'a']++;
            }
            else{
                c2[s1[i]-'a']++;
            }
        }
        vector<int> c11(26,0);
        vector<int> c22(26,0);

        for(int i=0;i<n2;i++){
            if(i%2==0){
                c11[s2[i]-'a']++;
            }
            else{
                c22[s2[i]-'a']++;
            }
        }

        for(int i=0;i<n2;i++){
            if(i%2==0){
                int f=c11[s2[i]-'a'];
                if(c1[s2[i]-'a']!=f){
                    return false;
                }
            }
            else{
                int f=c22[s2[i]-'a'];
                if(c2[s2[i]-'a']!=f){
                    return false;
                }

            }
        }

        return true; 


    }
};