class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> f;
        for(auto d:digits){
            f[d]++;
        }        

        int ans=0;

        for(int i=1;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<9;k+=2){
                    ans+=f[i] && f[j] > (i==j) && f[k] > ((i==k) + (j==k));
                }
            }
        }

        return ans;
    }
};