class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> f;
        int i=0;
        int n=fruits.size();
        int ans=0;
        for(int j=0;j<n;j++){
            f[fruits[j]]++;
            while(f.size()==3){
                f[fruits[i]]--;
                if(f[fruits[i]]==0){
                    f.erase(fruits[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
        }

        return ans;
    }
};