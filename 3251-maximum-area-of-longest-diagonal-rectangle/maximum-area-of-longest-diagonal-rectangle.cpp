class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area=0;
        int diagonal=0;
        int n=dimensions.size();
        for(int i=0;i<n;i++){
            int l=dimensions[i][0];
            int w=dimensions[i][1];
            if(l*l+(w*w)>diagonal){
                diagonal=l*l+(w*w);
                area=l*w;
            }
            else if(l*l+(w*w)==diagonal && l*w>area){
                area=l*w;
            }
        }

        return area;
    }
};