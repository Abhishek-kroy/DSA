class Solution {
public:
    bool isPowerOfFour(int n) {
        int mask = 0b01010101010101010101010101010101;
        return n>0 && 1073741824%n==0 && (n&mask)==n;
    }
};