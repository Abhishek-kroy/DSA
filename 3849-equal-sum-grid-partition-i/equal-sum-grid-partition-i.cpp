class Solution {
public:

    // bool ans(vector<long long>p,int l,int x){
    //     auto it = lower_bound(p.begin(), p.begin() + l + 1, x);
    //     return (it != p.begin() + l + 1 && *it == x);
    // }
    
    bool canPartitionGrid(vector<vector<int>>& grid) {
       
        long long sum=0;
        for(auto v:grid){
            for(auto val:v){
                sum+=val;
            }
        }

        long long s1=0;
        for(auto v:grid){
            for(auto val:v){
                s1+=val;
            }

            if(sum-s1==s1){
                return true;
            }
        }
        s1=0;
        for(int j=0;j<grid[0].size();j++){
            for(int i=0;i<grid.size();i++){
                s1+=grid[i][j];
            }

            if(sum-s1==s1){
                return true;
            }
        }

        return false;
        
    }
};

/*
long long sum=0;
        for(auto v:grid){
            for(auto val:v){
                sum+=val;
            }
        }

        long long s1=0;
        for(auto v:grid){
            for(auto val:v){
                s1+=val;
            }

            if(sum-s1==s1){
                return true;
            }
        }
        s1=0;
        for(int j=0;j<grid[0].size();j++){
            for(int i=0;i<grid.size();i++){
                s1+=grid[i][j];
            }

            if(sum-s1==s1){
                return true;
            }
        }

        return false;

*/