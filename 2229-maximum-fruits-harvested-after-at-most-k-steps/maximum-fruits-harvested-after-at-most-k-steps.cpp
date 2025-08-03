class Solution {
public:
    int steps(int l,int r,int st,vector<vector<int>>& fruits){
        if(fruits[r][0]<st){
            return st-fruits[l][0];
        }
        else if(st<fruits[l][0]){
            return fruits[r][0]-st;
        }

        return min(st-fruits[l][0]+(fruits[r][0]-fruits[l][0]),fruits[r][0]-st+(fruits[r][0]-fruits[l][0]));
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int l=0;
        int r=0;
        int n=fruits.size();

        int ans=0;

        int sum =0 ;

        while(r<n){


            while(l<=r && steps(l,r,startPos,fruits)>k){
                sum-=fruits[l][1];
                l++;
            }
            
            sum+=fruits[r][1];

            ans=max(ans,sum);
            r++;

        }

        return ans;



    }
};