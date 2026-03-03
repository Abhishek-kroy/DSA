class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int,int> f;
        int j=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val=nums[i];     
            
            // so for valueDiff+1=4 
            // -1 , -2 , -3 , -4 to -1 buc 
            
            int buc=val>=0 ? val/(valueDiff+1): (val+1)/(valueDiff+1)-1;  


            if(f.find(buc)!=f.end()){
                return true;
            }
            if(f.find(buc-1)!=f.end()){
                if(abs(f[buc-1]-val)<=valueDiff){
                    return true;    
                }
            }
            if(f.find(buc+1)!=f.end()){      
                if(abs(f[buc+1]-val)<=valueDiff){
                    return true;
                }
            }

            f[buc]=val;    

            if((i-j)==indexDiff){
                int v2=nums[j];
                int buc2=v2>=0 ? v2/(valueDiff+1): (v2+1)/(valueDiff+1)-1;    
                f.erase(buc2);
                j++;   
            }
        }

        return false;    
    }
};