class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int> lmax(n,0);
        vector<int> rmax(n,0);

        int left=0; 

        for(int i=0;i<n;i++){
            lmax[i]=left;

            left=max(left,height[i]);
        }

        int right=0; 

        for(int i=n-1;i>=0;i--){
            rmax[i]=right;

            right=max(right,height[i]);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            ans+=max(0,((min(lmax[i],rmax[i])-height[i])));          
        }

        return ans;    
        
    }
};