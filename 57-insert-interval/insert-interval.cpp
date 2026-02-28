class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if(intervals.size()==0){
            return {newInterval}; 
        }

        int n=intervals.size();


        vector<vector<int>> ans;
        int i=0;

        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        if(i>=n){
            ans.push_back(newInterval);
            return ans; 
        }

        if(intervals[i][0]<=newInterval[1]){
            int st=min(intervals[i][0],newInterval[0]);
            int end=max(intervals[i][1],newInterval[1]);

            while(i<n && intervals[i][0]<=end){
                end=max(end,intervals[i][1]);    
                i++;                      
            }

            ans.push_back({st,end});         
        }
        else{
            ans.push_back(newInterval); 
        }


        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans   ; 

    }    
};