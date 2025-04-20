#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        string se="";

        if((numerator*denominator)<0){
            se="-";
            numerator=abs(numerator);
            denominator=abs(denominator);
        }

        se += to_string(numerator / denominator);
        

        numerator %= denominator;

        if (!numerator) {
            return se;
        }

        se += ".";
        string dec = "";
        unordered_map<int, int> remainderIndex;

        while (numerator != 0) {
            if (remainderIndex.find(numerator) != remainderIndex.end()) {
                int index = remainderIndex[numerator];
                dec.insert(index, "(");
                dec += ")";
                break;
            }

            remainderIndex[numerator] = dec.size();
            
            numerator *= 10;
            int digit = numerator / denominator;
            dec += to_string(digit);
            numerator %= denominator;
            if (!numerator) {
                break;
            }
        }

        return se + dec;
    }
};