class Solution {
public:
    int getc(int v,int cur){
        int w1=v>=cur ? (v-cur) : (9-cur)+1+(v);
        int w2=v<=cur ? (cur-v) : (cur)+1+(9-v);

        return min(w1,w2);
    }
    int minRotations(int n, string s) {
        s="0"+s;
        int maxi=INT_MAX;
        int ind=0;
        n++;    

        for(int i=1;i<n;i++){

            int redc=getc(s[i]-'0',s[i-1]-'0');
            int inc=getc(s[n-1]-'0',s[i-1]-'0');
            if(inc-redc<maxi){
                maxi=inc-redc;
                ind=i;
            }
        }

        reverse(s.begin()+ind,s.end());

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