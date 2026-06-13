class Solution {
public:
    unordered_map<int,int> m;
    int getans(vector<int>& cost,int t){
        if(t>=(int)cost.size()){      
            return 0;
        }

        if(m.find(t)!=m.end()){
            return m[t];
        }

        if(t==-1){
            int w1=min(getans(cost,t+1),getans(cost,t+2));
            m[t]=w1;
            return  w1;
        }

        int w1=cost[t]+min(getans(cost,t+1),getans(cost,t+2));         
        m[t]=w1;

        return w1; 
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return getans(cost,-1);        
    }
};