class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=-1;
        int cnt1=0; 

        int ele2=-1;
        int cnt2=0; 

        int n=nums.size(); 

        for(int i=0;i<n;i++){
            if(nums[i]==ele1){
                cnt1++;
            }          
            else if(nums[i]==ele2){
                cnt2++;
            }          
            else if(cnt1==0){
                ele1=nums[i];
                cnt1=1;
            }                                        
            else if(cnt2==0){
                ele2=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--; 
            }
        }

        int c1=0;
        int c2=0;

        for(auto v:nums){
            if(v==ele1){
                c1++;
            }
            else if(v==ele2){ 
                c2++;
            }
        }

        vector<int> ans;

        if(c1>(int)nums.size()/3){
            ans.push_back(ele1);   
        }
        if(c2>(int)nums.size()/3){
            ans.push_back(ele2);   
        }

        return ans;    
    }
};