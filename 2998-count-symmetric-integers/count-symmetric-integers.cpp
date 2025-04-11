class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        while(low<=high){
            int v=low;
            low++;

            string val=to_string(v);
            int s1=0;
            int s2=0;
            if(val.size()%2){
                continue;
            }

            for(int i=0;i<val.size()/2;i++){
                s1+=(val[i]-'0');
            }
            for(int i=val.size()/2;i<val.size();i++){
                s2+=(val[i]-'0');
            }

            if(s1==s2){
                cout<<v<<endl;
                cnt++;
            }
        }

        return cnt;
    }
};