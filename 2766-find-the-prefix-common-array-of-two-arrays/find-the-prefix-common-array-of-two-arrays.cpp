class Solution {
public:
    int getval(long long n1,long long n2){
        int cnt=0;
        for(int i=0;i<64;i++){
            if(n1&(1LL<<i) && n2&(1LL<<i)){
                cnt++;
            }
        }

        return cnt;   
    }

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();

        long long n1=0;
        long long n2=0; 

        vector<int> C(n,0);

        for(int i=0;i<n;i++){
            int v1=A[i];
            n1|=(1LL<<v1);
            int v2=B[i];
            n2|=(1LL<<v2);

            C[i]=getval(n1,n2);
        }        

        return C;   
    }
};