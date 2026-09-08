class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();

        priority_queue<int,vector<int>,greater<int>> pq;

        int b=0;

        for(int i=1;i<n;i++){
            if(heights[i]-heights[i-1]>0){
                int v=heights[i]-heights[i-1];

                if(pq.size()<ladders){
                    pq.push(v);
                }
                else if(!pq.empty() && v>pq.top()){
                    int t=pq.top();

                    pq.pop();

                    b+=t;

                    pq.push(v);
                }
                else{
                    b+=v;
                }

                if(b<=bricks){
                    continue;
                }
                else{
                    return i-1;
                }
            }
        }

        return n-1;    
    }
};