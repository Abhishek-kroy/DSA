class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        int i=0;
        while(i<n){
            int st=intervals[i][0];
            int end=intervals[i][1];
            while(i<n && intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
                i++;
            }

            ans.push_back({st,end});
        }

        return ans;

    }
};