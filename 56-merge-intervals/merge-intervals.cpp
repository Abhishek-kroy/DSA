class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(),intervals.end());        

        int st=intervals[0][0];
        int end=intervals[0][1];


        int i=0;

        vector<vector<int>> ans;

        while(i<n){
            int st1=intervals[i][0];
            int end1=intervals[i][1];    

            if(st1>end){
                ans.push_back({st,end});
                st=st1;
                end=end1;
            }
            else{
                end=max(end,end1);
            }

            i++;
        }       

        ans.push_back({st,end});

        return ans;         
    }
};