class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n,-1);        

        for(int i=0;i<n;i++){
            int val=nums[i];
            if((val%2)==0){
                continue; 
            }
            int pos=0;
            while(val>0){
                if((val&1)==0){  
                    break;
                }
                pos++;
                val>>=1;      
            }

            int value=nums[i]&(~(1<<(pos-1)));  

            a[i]=value;
        }

        return a ; 
    }
};