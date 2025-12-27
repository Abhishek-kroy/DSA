#define ii pair<int,int> 

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        vector<int> ans(2,-1);     

        int n=nums.size();
        vector<int> ptr(n);

        priority_queue<ii> right;

        int l=INT_MAX;
        for(int i=0;i<n;i++){
            int ptr_value=nums[i].size()-1;
            ptr[i]=ptr_value; 
            l=min(l,nums[i][ptr_value]); 
            right.push({nums[i][ptr_value],i}); 
        }

        while(right.size()==n){
            auto [r,i]=right.top();
            right.pop();

            if(ans[0]==-1){
                ans[0]=l;
                ans[1]=r;
            }
            else{
                int a=ans[0];
                int b=ans[1];

                if(((b-a)>(r-l)) || ((b-a)==(r-l) && l<a)){
                    ans[0]=l;
                    ans[1]=r;
                }
            }

            int pt=ptr[i];
            if(pt>0){
                pt--;
                l=min(l,nums[i][pt]);  
                right.push({nums[i][pt],i});
                ptr[i]=pt; 
            }
        }

        return ans;         
    }
};