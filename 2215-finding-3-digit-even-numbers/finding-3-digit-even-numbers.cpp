class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> f(10,0);
        for(auto d:digits){
            f[d]++;
        }

        vector<int> ans;

        for(int i=100;i<999;i+=2){
            int v1=i/100;
            int v2=(i%100)/10;
            int v3=i%10;
            bool pos=true;
            if(f[v1]<=0){
                pos=false;
            }
            f[v1]--;
            if(f[v2]<=0){
                pos=false;
            }
            f[v2]--;
            if(f[v3]<=0){
                pos=false;
            }
            f[v2]++;
            f[v1]++;
            if(pos)
                ans.push_back(i);

        }

        return ans;
    }
};