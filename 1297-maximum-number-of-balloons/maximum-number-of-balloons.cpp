class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // balloon 

        unordered_map<char,int> f;

        for(auto c:text){
            f[c]++;
        }

        int ans=f['b'];

        string v="balloon";

        for(auto c:v){               
            if(c=='l' || c=='o'){
                ans=min(ans,f[c]/2);
            }
            else{
                ans=min(ans,f[c]);
            }
        }

        return ans; 
    }
};