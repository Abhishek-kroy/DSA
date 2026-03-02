class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int ans = 0;
        int n = points.size();

        if(n <= 2) return n;

        unordered_map<int,int> f;

        for(int i = 0; i < n; i++){
            double x1 = points[i][0];
            double y1 = points[i][1];

            f[x1]++;

            for(int j = i + 1; j < n; j++){
                double x2 = points[j][0];
                double y2 = points[j][1];

                if(x2 == x1) continue;

                double m = (y2 - y1) / (x2 - x1);
                double c = y2 - m * x2;

                int cnt = 0;

                for(int k = 0; k < n; k++){
                    double x3 = points[k][0];
                    double y3 = points[k][1];

                    if(abs(m * x3 + c - y3) <= 1e-5){
                        cnt++;
                    }
                }

                ans = max(ans, cnt);
            }
        }

        for(auto p : f){
            ans = max(ans, p.second);
        }

        return ans;
    }
};    