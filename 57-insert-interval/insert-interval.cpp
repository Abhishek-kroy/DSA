class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        int st=intervals[0][0];
        int end=intervals[0][1];
        int n=intervals.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(st==-1){
                st=intervals[i][0];
                end=intervals[i][1];
                continue;
            }
            if(intervals[i][0]<=end){
                end=max(intervals[i][1],end);
            }
            else{
                ans.push_back({st,end});
                st=intervals[i][0];
                end=intervals[i][1];
            }
        }
        
        ans.push_back({st,end});

        return ans;
    }
};