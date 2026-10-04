class Solution {
public:
    int minRotations(string s) {
        int t=0;

        int cur=0;

        for(auto c:s){
            int v=c-'0';
            int w1=v>=cur ? (v-cur) : (9-cur)+1+(v);

            int w2=v<=cur ? (cur-v) : (cur)+1+(9-v);
            // cout<<min(w1,w2)<<endl;    

            cur=v;    

            t+=min(w1,w2);
        }

        return t;
    }
};