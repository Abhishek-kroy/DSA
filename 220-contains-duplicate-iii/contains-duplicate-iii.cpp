class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        int l=0;
        int r=0;

        multiset<int> s;

        while(r<n){
            s.insert(nums[r]);
            if((r-l)==indexDiff){
                s.erase(s.find(nums[l]));
                int val=nums[l];
                int left=val-valueDiff;
                int right=val+valueDiff;    
                auto it1=s.lower_bound(left);

                if(it1!=s.end() && *it1>=left && *it1<=right){
                    return true;
                }
                l++;
            }
            r++;
        }

        while(l<n){
            s.erase(s.find(nums[l]));
            int val=nums[l];
            int left=val-valueDiff;
            int right=val+valueDiff;    
            auto it1=s.lower_bound(left);    

            if(it1!=s.end() && *it1>=left && *it1<=right){
                return true;
            }    
            l++;    
        }

        return false ;    
    }
};