class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> f;

        int n=fruits.size();

        int ans=0;
        int j=0;

        for(int i=0;i<n;i++){
            f[fruits[i]]++;

            while(f.size()>2){
                f[fruits[j]]--;

                if(f[fruits[j]]==0){
                    f.erase(fruits[j]);
                }

                j++;         
            }

            ans=max(ans,i-j+1); 
        }

        return ans; 
    }
};