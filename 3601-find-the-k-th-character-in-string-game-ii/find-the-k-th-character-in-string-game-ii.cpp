class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n=operations.size();

        vector<int> op;
        long long length=k;
        while(length>1){
            int ind=log2(length);
            if((length&(length-1))!=0){
                ind++;
            }
            op.push_back(operations[ind-1]);

            long long len=length-(1LL<<(ind-1));

            length=len;
        }
        reverse(op.begin(),op.end());

        int c=0;

        for(auto v:op){
            if(v==1){
                c=(c+1)%26;
            }
        }

        return 'a'+c;
    }
};