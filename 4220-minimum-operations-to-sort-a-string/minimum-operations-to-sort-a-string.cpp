class Solution {
public:
    int minOperations(string s) {

        int n=s.size();

        string t=s;    
        sort(t.begin(),t.end());

        if(s==t){
            return 0;
        }

        if(s.size()==2 && s[0]>s[1]){
            return -1;
        }

        int st=-1;
        int end=-1;

        for(int i=0;i<s.size();i++){
            if(s[i]==t[0] && st==-1){
                st=i;
            }
            else if(s[i]==t[n-1]){    
                end=i;
            }
        }    

        if(st==0 || end==n-1){    
            return 1;
        }

        if(st==n-1 && end==0){    
            return 3;
        }

        return 2; 


    }
};