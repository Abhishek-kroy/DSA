class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int val=INT_MAX;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            val=min(val,abs(arr[i]-arr[i+1]));
        }

        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])==val){
                ans.push_back({arr[i],arr[i+1]});
            }
        }

        return ans;
    }
};