// class Solution {
// public:
//     vector<int> bits;
//     unordered_map<int,int> dp;

//     void getans(string& left, string& right, int tight, int i) {
//         int n = right.size();
//         if (i == n) return;


//         int l = tight ? (left[i] - '0') : 0;
//         int r = right[i] - '0';

//         for (int b = l; b <= r; b++) {
//             int newTight = tight && (b == r);
//             if (b == 0) bits[i] = 0;  // If any path has 0 in this bit, AND will be 0
//             getans(left, right, newTight, i + 1);
//         }
//     }

//     string getBinary(int num) {
//         string res = "";
//         while (num) {
//             res = char((num & 1) + '0') + res;
//             num >>= 1;
//         }
//         return res.empty() ? "0" : res;
//     }

//     int rangeBitwiseAnd(int left, int right) {
//         string l = getBinary(left);
//         string r = getBinary(right);
//         // Pad left with leading zeros to match right
//         while (l.size() < r.size()) {
//             l = '0' + l;
//         }

//         int n = r.size();
//         bits.assign(n, 1);  // Initially set all bits to 1

//         getans(l, r, 1, 0);

//         // Convert bits to integer
//         int num = 0;
//         for (int i = 0; i < n; i++) {
//             num = (num << 1) | bits[i];
//         }

//         return num;
//     }
// };
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};
// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         while (left < right) {
//             right &= (right - 1); // Remove the rightmost set bit
//         }
//         return right;
//     }
// };