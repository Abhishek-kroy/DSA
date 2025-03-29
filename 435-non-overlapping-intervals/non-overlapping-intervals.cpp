class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });

        for(auto i:intervals){
            cout<<i[0]<<" "<<i[1]<<endl;
        }

        int cnt=0;
        for(int i=0;i<intervals.size();i++){
            int st=intervals[i][0];
            int end=intervals[i][1];
            int j=i+1;
            while(j<intervals.size() and intervals[j][0]<end){
                cnt++;
                j++;
            }

            i=j-1;
        }

        return cnt;
    }
};