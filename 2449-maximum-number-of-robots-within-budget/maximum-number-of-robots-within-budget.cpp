class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int i=0;
        int j=0;
        int n=chargeTimes.size();
        long long rc=0;
        // int v=0;
        deque<int> v;
        int ans=0;
        while(j<n){
            while(!v.empty() && v.back()<chargeTimes[j]){
                v.pop_back();
            }
            v.push_back(chargeTimes[j]);
            rc+=runningCosts[j];
            if(v.front()+(j-i+1)*rc<=budget){
                ans=max(ans,(j-i+1));
            }
            else{
                while(1LL*v.front()+1LL*(j-i+1)*rc>budget){
                    if(!v.empty() && chargeTimes[i]==v.front()){
                        v.pop_front();
                    }
                    rc-=runningCosts[i];
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};