class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return 0;    
        }

        int i=0;

        int end=0;

        int j=1;

        while(i<n){
            int r=end;

            while(i<n && i<=end){
                r=max(r,i+nums[i]);
                i++;
            }

            if(r>=n-1){
                return j;                
            }

            j++;

            end=r;
        }

        return -1;        
    }
};