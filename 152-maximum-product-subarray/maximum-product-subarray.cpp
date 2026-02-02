class Solution {
public:
    int getans(vector<int>& nums,int i,int j,int negcount,int left,int right){
        if(j<i){
            return INT_MIN;   
        }

        if(negcount%2==0){
            int cnt=1;
            for(int k=i;k<=j;k++){
                cnt*=nums[k];
            }

            return cnt;  
        }
        return max(getans(nums,i,right-1,negcount-1,left,right),getans(nums,left+1,j,negcount-1,left,right))   ; 
    }

    int maxProduct(vector<int>& nums) {
        nums.push_back(0);
        int l=0;
        int r=0;
        int n=nums.size();

        int ans=nums[0]; 
        int neg=0;
        int left=-1;
        int right=-1;

        while(r<n){
            if(nums[r]==0){
                ans=max(ans,getans(nums,l,r-1,neg,left,right));
                if(r!=n-1)
                    ans=max(ans,0);   
                l=r+1;
                neg=0;
                left=-1;
                right=-1;
            }
            if(nums[r]<0){  
                neg++;
                if(left==-1){
                    left=r;
                    right=r;
                }
                else{
                    right=r;
                }
            }
            r++; 
        }

        return ans;
    }
};