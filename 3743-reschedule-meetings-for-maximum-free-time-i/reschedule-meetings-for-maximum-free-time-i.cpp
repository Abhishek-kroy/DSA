class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> ft;
        int st=0;
        for(int i=0;i<startTime.size();i++){
            ft.push_back(startTime[i]-st);
            st=endTime[i];
        }
        ft.push_back(eventTime-st);
        // 1 1 0
        int i=0;
        int j=0;
        int n=startTime.size();
        int ans=0;
        int v=0;
        while(j<ft.size()){
            v+=ft[j];
            ans=max(ans,v);
            if(j-i+1==k+1){
                v-=ft[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};