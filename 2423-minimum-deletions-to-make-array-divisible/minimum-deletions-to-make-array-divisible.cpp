class Solution {
public:
    // int gcd(int a,int b){
    //     while(b){


    //     }
    // }




    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=nums.size();

        int a=0;

        for(auto v:numsDivide){
            a=__gcd(a,v);
        }

        sort(nums.begin(),nums.end());

        int cnt=0;






        for(auto v:nums){
            if(a%v==0){
                return cnt;
            }              

            cnt++;          
        }

        return -1; 
    }
};