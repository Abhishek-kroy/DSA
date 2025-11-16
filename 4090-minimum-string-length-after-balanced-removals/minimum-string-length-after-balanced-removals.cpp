class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cnta=0,cntb=0;
        for(auto c:s){
            if(c=='a') cnta++;
            else cntb++;
        }

        return abs(cnta-cntb);
    }
};