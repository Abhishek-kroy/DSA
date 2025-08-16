class Solution {
public:
    int minSensors(int n, int m, int k) {
        int len=2*k+1;
        return(int)ceil((double(n)/len))*ceil((double)m/len);
    }
};