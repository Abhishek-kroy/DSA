class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>> fx;
        unordered_map<int,pair<int,int>> fy;

        for(auto b:buildings){
            int x=b[0];
            int y=b[1];
            if(fx.find(x)==fx.end()){
                fx[x]={y,y};
            }
            if(fy.find(y)==fy.end()){
                fy[y]={x,x}; 
            }
            fx[x].first=min(fx[x].first,y);
            fx[x].second=max(fx[x].second,y);
            fy[y].first=min(fy[y].first,x);
            fy[y].second=max(fy[y].second,x); 
        }

        int cnt=0;

        for(auto b:buildings){
            int x=b[0];
            int y=b[1]; 
            if(fx[x].first<y and fx[x].second>y and fy[y].first<x and fy[y].second>x){
                cnt++;
            }
        }

        return cnt;         
    }
};