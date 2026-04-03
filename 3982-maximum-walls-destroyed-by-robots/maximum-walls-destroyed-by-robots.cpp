class Solution {
public:
    int getcnt(vector<int>& w, int l, int r){
        if(l > r) return 0;
        int L = lower_bound(w.begin(), w.end(), l) - w.begin();
        int R = upper_bound(w.begin(), w.end(), r) - w.begin();
        return R - L;
    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size();
        vector<vector<int>> r(n+2,vector<int> (2));   

        sort(walls.begin(),walls.end());

        r[0]={0,0};   

        for(int i=0;i<n;i++){
            r[i+1]={robots[i],distance[i]};
        }

        r[n+1]={(int)1e9+1,0};       



        sort(r.begin(),r.end());

        vector<int> dpleft(n+2);
        vector<int> dpright(n+2);

        dpleft[0]=0;
        dpright[0]=0;   

        for(int i=1;i<n+1;i++){

            // robot i in left and robot i-1 in left
            int w1=getcnt(walls,max(r[i-1][0]+1,r[i][0]-r[i][1]),r[i][0])+dpleft[i-1];

            // robot i in left and robot i-1 in right
            int w2=getcnt(walls,max(r[i-1][0]+1,r[i][0]-r[i][1]),r[i][0])+dpright[i-1]-getcnt(walls,max(r[i-1][0]+1,r[i][0]-r[i][1]),min(r[i][0]-1,r[i-1][0]+r[i-1][1]));   

            dpleft[i]=max(w1,w2);  

            // robot i in right and robot i-1 in left
            int w3=getcnt(walls,r[i][0],min(r[i+1][0]-1,r[i][0]+r[i][1]))+dpleft[i-1];
            // robot i in right and robot i-1 in right
            int w4=getcnt(walls,r[i][0],min(r[i+1][0]-1,r[i][0]+r[i][1]))+dpright[i-1];

            dpright[i]=max(w3,w4);   

        }

        return max(dpleft[n],dpright[n]);   
    }
};