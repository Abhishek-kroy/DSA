class cmp{
    public:
        bool operator()(vector<int>& a,vector<int>& b){
            long long x1=a[0];
            long long y1=a[1];

            long long x2=b[0];
            long long y2=b[1];      

            return x1*x1+y1*y1< x2*x2+y2*y2 ; 

        }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),cmp());

        vector<vector<int>> ans(k);

        for(int i=0;i<k;i++){
            ans[i]=points[i];
        }

        return ans;      
    }
};