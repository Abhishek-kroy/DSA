class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l = INT_MAX, h = INT_MIN;

        for (auto& sqr : squares) {
            l = min(l, (double)sqr[1]);             
            h = max(h, (double)(sqr[1] + sqr[2]));       
        }

        while (h - l > 1e-5) {
            double m = (l + h) / 2.0;
            double A = 0, B = 0;   

            for (auto& sqr : squares) {  
                double y_1 = sqr[1];               
                double y_2 = y_1 + sqr[2];          
                double side = (double)sqr[2];     

                if (m >= y_2) {
                    B += side * side; 
                } else if (m <= y_1) {
                    A += side * side; 
                } else {
                    double below = (m - y_1) * side;  
                    double above = (y_2 - m) * side;  
                    B += below;
                    A += above;
                }
            }

            if (A > B) {
                l = m;  
            } else {
                h = m; 
            }
        }

        return l;
    }
};