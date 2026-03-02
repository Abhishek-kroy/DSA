class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();

        if(n<=2){
            return n; 
        }

        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];

            int cnt=0;

            // unordered_map<double,int> f;      
            unordered_map<string,int> f1;      

            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }

                int x2=points[j][0];    
                int y2=points[j][1];

                int dy=y2-y1;
                int dx=x2-x1;

                int gcd=__gcd(dy,dx);

                dy=dy/gcd;
                dx=dx/gcd;

                string key=to_string(dy)+"_"+to_string(dx);

                f1[key]++;
                cnt=max(cnt,f1[key]);         
                
                // double m=atan2(dy,dx);                   

                // if(dx!=0){
                // }

                // f[m]++;

                // cnt=max(cnt,f[m]);

            }

            ans=max(ans,cnt+1);

            // for(auto p:f){
            //     ans=max(ans,1+p.second);  
            // }


        }   

        return ans;  
    }
};