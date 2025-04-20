class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // int n=answers.size();
        // int ans=0;
        // for(int i=0;i<answers.size();i++){
        //     if(answers[i]==-1)  continue;

        //     int oth=answers[i]+1;
        //     int v=answers[i];
        //     ans+=oth;

        //     for(int j=i;j<n && oth;j++){
        //         if(v==answers[j]){
        //             answers[j]=-1;
        //             oth--;
        //         }
        //     }
        // }


        unordered_map<int,int> dp;
        for(auto v:answers){
            dp[v+1]++;
        }

        int ans=0;

        for(auto [n,f]:dp){
            ans+=(((f+n-1)/n)*n);
        }

        return ans;
    }
};