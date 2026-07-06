class cmp{
    public :             
    bool operator()(vector<int>& a,vector<int>& b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }

        return a[1]>b[1]; 
    }
};

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp());

        int st=intervals[0][0];
        int end=intervals[0][1];

        int cnt=0; 

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][1]<=end){
                continue;
            }
            else{
                cnt++;
                st=intervals[i][0];
                end=intervals[i][1];
            }
        }

        cnt++;

        return cnt; 
    }
};