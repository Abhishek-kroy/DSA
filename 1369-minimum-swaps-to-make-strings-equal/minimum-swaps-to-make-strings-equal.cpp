class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy=0;
        int yx=0;

        for(int i=0;i<s1.size();i++){
            if(s1[i]=='x' and s2[i]=='y'){
                xy++;
            }
            if(s1[i]=='y' and s2[i]=='x'){
                yx++;
            }
        }

        int cnt=(xy/2)+(yx/2);
        xy%=2;
        yx%=2;

        if(xy==0 and yx==0){
            return cnt;
        }
        if(xy==1 and yx==0){
            return -1;
        }
        if(xy==0 and yx==1){
            return -1;
        }

        return cnt+2;

    }
};